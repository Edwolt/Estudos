#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll fibonacci(int n) {
    ll a = 1, b = 1, aux;

    for (int i = 2; i < n; i++) {
        aux = b;
        b = a;
        a = a + aux;
    }

    return a;
}

int main() {
    ll n;
    cin >> n;

    cout << fibonacci(n) << endl;
}
