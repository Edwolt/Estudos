#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int MAXN = 1e5;

struct aresta {
    int vertice, peso;

    bool operator<(const aresta& that) const {
        return this->peso > that.peso;
    }
};

int n, m;
vector<aresta> grafo[MAXN];
int distancia[MAXN];

void dijkstra(int pos) {
    memset(distancia, INF, sizeof(distancia));
    priority_queue<aresta> pq;
    distancia[pos] = 0;

    pq.push({pos, 0});

    while (!pq.empty()) {
        int u = pq.top().vertice;
        int d = pq.top().peso;
        cout << u << endl;
        pq.pop();

        // Poupa processamento
        if (d > distancia[u])
            continue;

        for (int i = 0; i < grafo[u].size(); i++) {
            int v = grafo[u][i].vertice;
            int w = grafo[u][i].peso;

            if (distancia[u] + w < distancia[v]) {
                distancia[v] = distancia[u] + w;
                pq.push({v, distancia[v]});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        grafo[u].push_back({v, w});
        grafo[v].push_back({u, w});
    }

    dijkstra(0);
    for (int i = 0; i < n; i++) {
        printf("%d dista %d\n", i, distancia[i]);
    }
}
