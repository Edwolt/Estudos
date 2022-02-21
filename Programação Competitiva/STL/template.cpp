#include <bits/stdc++.h>
using namespace std;

template <typename T>
T maximo(T a, T b) {
    if (a >= b) return a;
    return b;
}

template <typename U>
struct vetor_3D {
    U x, y, z;
};

int main() {
    printf("Máximo(  1  ,  2  ) = %d\n", maximo(1, 2));
    printf("Máximo(  2  ,  1  ) = %d\n", maximo(1, 2));
    printf("Máximo(  2  ,  1  ) = %d\n", maximo<int>(1, 2));
    printf("Máximo( 2.4 , 2.3 ) = %lf\n", maximo(2.4, 2.3));
    printf("Máximo( 2.4 , 2.3 ) = %f\n", maximo<float>(2.4, 2.3));
    pair<int, int> mp = maximo<pair<int, int>>({2, 4}, {2, 3});
    printf("Máximo((2,4),(2,3)) = (%d,%d)\n", mp.first, mp.second);
}
