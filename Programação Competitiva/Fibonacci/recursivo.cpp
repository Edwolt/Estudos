#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ll n = 30;
    cout << fibonacci(n) << endl;
}
