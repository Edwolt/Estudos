/*
TODO: Esse código tem problema e não roda corretamente
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

struct union_find {
    int parent[MAXN];
    vector<int> rank = vector<int>(1, MAXN);  // Altura da subarvore

    union_find() {
        for (int i = 0; i < MAXN; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return find(parent[x]);
        }
    }

    // * Muito Devagar *
    // void join(int x, int y)
    // {
    //     parent[find[x]] = find(y);
    // }

    void join(int x, int y) {
        int raiz_x = find(x);
        int raiz_y = find(y);

        if (raiz_x == raiz_y) {
            return;
        }

        if (rank[raiz_x] < rank[raiz_y]) {
            parent[raiz_x] = raiz_y;
            rank[raiz_y] = max(rank[raiz_y], rank[raiz_x] + 1);
        } else {
            parent[raiz_y] = raiz_x;
            rank[raiz_x] = max(rank[raiz_x], rank[raiz_y] + 1);
        }
    }
};

struct edge {
    int u, v, w;

    bool operator<(edge &that) const {
        return this->w < that.w;
    }
};

int n, m;
vector<edge> grafo[MAXN];
vector<edge> mst;

int kruskal() {
    union_find uf;
    int total = 0;
    vector<edge> edges;

    for (auto v : grafo) {
        for (auto e : v) {
            edges.push_back(e);
        }
    }

    sort(edges.begin(), edges.end());

    int added = 0;

    for (auto e : edges) {
        int conj1 = uf.find(e.u);
        int conj2 = uf.find(e.v);

        if (conj1 == conj2) {
            continue;
        }

        uf.join(conj1, conj2);
        total += e.w;
        added++;
        mst.push_back(e);

        if (added == n - 1) {
            break;
        }
    }

    return total;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        grafo[u].push_back({u, v, w});
        grafo[v].push_back({v, u, w});
    }

    cout << kruskal() << endl;
}
