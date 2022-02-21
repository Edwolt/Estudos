#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    if (b == 0) return a;
    return (mdc(b, a % b));
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}
