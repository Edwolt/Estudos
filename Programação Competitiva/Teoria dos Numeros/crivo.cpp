// Crivo de Eratóstenes
// O(ln(x))

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int tab[N + 1] = {false};

void crivo() {
    for (int i = 2; i <= N; i++) {
        if (!tab[i]) {
            for (int j = i; j <= N; j += i) {
                tab[j] = i;
            }
        }
    }
}

void crivo_apenas_saber_se_e_primo() {
    for (int i = 2; i <= N; i++) {
        if (!tab[i]) {
            for (int j = i * i; j <= N; j += i) {
                tab[j] = i;
            }
        }
    }
}
