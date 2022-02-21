#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
const int MAXN = 1e5;

ll dp[MAXN];

ll fibonacci(int n) {
    if (dp[n] == -1) {
        dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    ll n;
    cin >> n;

    cout << fibonacci(n) << endl;
}
