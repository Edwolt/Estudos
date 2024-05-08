#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
using vi = vector<int>;
using qi = queue<int>;

int n, m;
vi grafo[N];

vi bfs(int pos) {
    vi distancia(n, -1);
    qi q;
    q.push(pos);
    distancia[pos] = 0;

    while (!q.empty()) {
        int atual = q.front();
        q.pop();

        for (int proximo : grafo[atual]) {
            if (distancia[proximo] == -1) {
                distancia[proximo] = distancia[atual] + 1;
                q.push(proximo);
            }
        }
    }
    return distancia;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    vi distancia = bfs(0);
    cout << "Distâncias: ";
    for (int i : distancia) {
        cout << i << " ";
    }
    cout << endl;
}
