#include <bits/stdc++.h>
using namespace std;

vector<int> divisores_primos(int n) {
    vector<int> div;
    for (int i = 2; i * i <= n; i++) {
        int c = 0;
        while (n % i) {
            div.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        div.push_back(n);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> div = divisores_primos(n);
    sort(div.begin(), div.end());

    for (int i : div) cout << i << " ";
    cout << endl;
}
