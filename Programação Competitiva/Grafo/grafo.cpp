// Forma de representar um grafo

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;  // Número de vertices e número de arestas
vector<int> grafo[MAXN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        // A maioria das vezes o problema começará no 1, então eu subtraio por 1 o u e o v
        grafo[u].push_back(v);
        grafo[v].push_back(u);  // Grafo não direcionado
    }
}
