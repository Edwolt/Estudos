#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

vector<int> divisores(int n) {
    vector<int> div;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            int complementar = n / i;
            if (complementar != i) {
                div.push_back(complementar);
            }
        }
    }
    return div;
}

int main() {
    int n;
    cin >> n;

    vector<int> div = divisores(n);
    sort(div.begin(), div.end());
    for (int i : div) cout << i << " ";

    cout << endl;
}
