#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> ms;
    ms["abc"] = 10;

    string s;
    cin >> s;
    ms[s]++;

    map<int, int> m;
    m[10] = 4;
    m.erase(10);  // Some com a chave 10 e seu valor que é 4

    m[1] = 5;
    m.find(1);   // Retorna m.end() se não encontrar o valor senão retorna o iterador para aquela posição
    m.count(1);  // Quantas vezes a chave 1 aparece (só pode ser 0 ou 1, pois é impossível ter chaves iguais)

    for (auto i = m.begin(); i != m.end(); i++) {
        int key = i->first;
        int val = i->second;
    }
}
