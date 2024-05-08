#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define ld long double

ll fibonacci(int n) {
    ld res =
        (1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));

    return (ll)res;
}

int main() {
    ll n = 30;
    cout << fibonacci(n) << endl;
}
