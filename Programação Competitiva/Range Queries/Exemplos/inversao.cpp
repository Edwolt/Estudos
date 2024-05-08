// Contar número de inversões
// Uma inversão acontece quando i < n e A[i] > A[j]

// Muito provável que a solução esteja errada

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int bits[MAXN];
int v[MAXN];
int n;

void update(int chave, int x)
{
    for (int i = chave; i <= n; i += i & (-i))
    {
        bits[i] += x;
    }
}

int query(int chave)
{
    int soma;
    for (int i = chave; i > 0; i -= i & (-i))
    {
        soma += bits[i];
    }
    return soma;
}

int main()
{
    cin >> n;
    int inv;

    for (int i = 0; i < n; i++)
    {
        update(v[i], i);
        inv += query(v[i] + 1);
    }

    for (int i = 0; i < n; i++)
    {
        int o;
        cin >> o;
        update(o, 1);
        inv += query(o + 1);
    }
}