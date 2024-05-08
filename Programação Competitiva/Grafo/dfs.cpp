#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int N = 1e5;

int n, m;
vector<int> grafo[N];

void dfs(int pos, vector<bool> &visitado) {
    if (visitado[pos]) {
        return;
    }

    // Estou marcando com true os nós visitados para evitar entrar em loop
    // infinito
    visitado[pos] = true;

    for (auto i : grafo[pos]) {
        dfs(i, visitado);
    }

    return;
}
vector<bool> dfs(int pos) {
    vector<bool> visitado(n, false);
    dfs(pos, visitado);
    return visitado;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        grafo[u].push_back(v);
        grafo[v].push_back(u);  // Grafo não orientado
    }

    vector<bool> visitado = dfs(0);

    cout << "Visitados: ";
    for (bool b : visitado) {
        cout << (b ? 'S' : 'n');
    }
    cout << endl;
}
