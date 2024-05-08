#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
using vi = vector<int>;
const int N = 1e5;

struct aresta {
    int v, w;
    bool operator<(const aresta &that) const {
        return this->v > that.w;
    }
};

int n, m;
vector<aresta> grafo[N];

vi dijkstra(int pos) {
    vi distancia(n, INF);
    priority_queue<aresta> pq;
    distancia[pos] = 0;

    pq.push({pos, 0});
    while (!pq.empty()) {
        int u = pq.top().v;
        int d = pq.top().w;
        cout << "Processando " << u << endl;
        pq.pop();

        // Poupa processamento
        if (d > distancia[u]) {
            continue;
        }

        for (int i = 0; i < grafo[u].size(); i++) {
            int v = grafo[u][i].v;
            int w = grafo[u][i].w;

            if (distancia[u] + w < distancia[v]) {
                distancia[v] = distancia[u] + w;
                pq.push({v, distancia[v]});
            }
        }
    }

    return distancia;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        grafo[u].push_back({v, w});
        grafo[v].push_back({u, w});
    }

    vi distancia = dijkstra(0);
    for (int i = 0; i < n; i++) {
        printf("%d dista %d\n", i, distancia[i]);
    }
}
