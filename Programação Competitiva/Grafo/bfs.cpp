#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;
vector<int> grafo[MAXN];
int distancia[MAXN];

void bfs(int pos) {
    memset(distancia, -1, sizeof(distancia));
    queue<int> q;
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
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
}
