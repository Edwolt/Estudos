#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int seg[4 * MAXN];
int v[MAXN];
int n;

void build(int p, int l, int r) {
    if (l == r) {
        seg[p] = v[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}

void build() {
    build(1, 1, n);
}

void update(int p, int l, int r, int pos, int x) {
    if (l == r && l == pos) {
        seg[p] = x;
    } else if (pos > r || pos < l) {
        return;
    } else {
        int mid = (l + r) / 2;
        update(2 * p, l, mid, pos, x);
        update(2 * p + 1, mid + 1, r, pos, x);
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}

void update(int pos, int valor) {
    update(1, 1, n, pos, valor);
}

int range_query(int p, int l, int r, int a, int b) {
    if (l >= a && r <= b) {
        return seg[p];  // Encaixa interamente no range
    }
    if (l > b || r < a) {
        return 0;  // Fora do range
    }
    int mid = (l + r) / 2;
    return range_query(2 * p, l, mid, a, b) +
           range_query(2 * p + 1, mid + 1, r, a, b);
}

int range_query(int a, int b) {
    return range_query(1, 1, n, a, b);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build();

    int k, c;
    cin >> k >> c;
    update(k, c);
    int l, r;
    cin >> l;
    cin >> r;

    cout << range_query(l, r);
}
