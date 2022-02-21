#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;
vector<int> grafo[MAXN];
bool visitado[MAXN];

void dfs(int pos) {
    if (visitado[pos]) {
        return;
    }

    // Estou marcando com true os nós visitados para evitar entrar em loop infinito
    visitado[pos] = true;

    for (auto i : grafo[pos]) {
        dfs(i);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);  // Grafo não orientado
    }
}
