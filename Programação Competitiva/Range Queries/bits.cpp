// Não Testado
// Range Query e Point Update

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int bits[MAXN];
int n;

// Não tem Build, cada vez que eu ler tenho que dar update
void update(int chave, int x) {
    for (int i = chave; i <= n; i += i & (-i)) {
        bits[i] += x;
    }
}

int query(int chave) {
    int soma;
    for (int i = chave; i > 0; i -= i & (-i)) {
        soma += bits[i];
    }
    return soma;
}
