#include <bits/stdc++.h>
using namespace std;

bool palindromo(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    cout << (palindromo(s) ? "eh palindromo" : "nao eh palindromo") << endl;
}
