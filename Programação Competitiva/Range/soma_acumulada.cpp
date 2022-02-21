#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int acc[MAXN + 1];

int main() {
    int n;
    cin >> n;

    acc[0] = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        acc[i] = x + acc[i - 1];
    }

    int l, r;
    cin >> l >> r;
    cout << acc[r] - acc[l - 1];
}
