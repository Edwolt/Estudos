#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define TAM 2

/*
 *  | F(n)   |  =  | 1  1 | * | F(n-1) |  =  | F(n-1) + F(n-2) |
 *  | F(n-1) |     | 1  0 |   | F(n-2) |     | F(n-1)          |
 *
 *  | F(n)   |  =  | 1  1 |^(n-2) * | 1 |
 *  | F(n-1) |     | 1  0 |         | 1 |
 */

struct Matriz {
    ll mat[TAM][TAM];

    Matriz operator*(const Matriz& that) const {
        Matriz res;

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < TAM; k++) {
                    res.mat[i][j] += this->mat[i][k] * that.mat[k][j];
                }
            }
        }
        return res;
    }

    Matriz pow(int n) {
        if (n == 1) {  // Talvez você que M^0 de identidade
            return *this;
        }
        Matriz res = this->pow(n / 2);
        if (n % 2 == 0) {
            return res * res;
        } else {
            return (*this) * (res * res);
        }
    }
};

int main() {
    ll n;
    cin >> n;

    Matriz m = {{{1, 1},
                 {1, 0}}};

    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    m = m.pow(n - 2);

    ll res = 0;
    for (int i = 0; i < TAM; i++) {
        res += m.mat[0][i];
    }

    cout << res << endl;
}
