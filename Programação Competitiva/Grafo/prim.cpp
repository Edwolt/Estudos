#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

struct edge {
    int vertice, peso;
    bool operator<(const edge& that) const {
        return this->peso > that.peso;
    }
};

int n, m;

bool vis[MAXN];
vector<edge> grafo[MAXN];

int prim() {
    priority_queue<edge> pq;

    for (edge i : grafo[0]) {
        pq.push(i);
    }
    vis[0] = true;
    int total = 0;

    while (!pq.empty()) {
        edge e = pq.top();
        pq.pop();

        if (!vis[e.vertice]) {
            vis[e.vertice] = true;
            total += e.peso;

            for (edge i : grafo[e.vertice]) {
                pq.push(i);
            }
        }
    }
    return total;
}

int main() {
    cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        vis[i] = false;
        cin >> u >> v >> w;
        grafo[u].push_back({v, w});
        grafo[v].push_back({u, w});
    }

    int res = prim();
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "Não foi possível visitar todos o vértices" << endl;
            return 0;
        }
    }

    cout << res << endl;
}
