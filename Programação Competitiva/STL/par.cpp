#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> aluno;
    int nota = aluno.first;
    string nome = aluno.second;

    vector<pair<int, int>> aux;  // Alguns compiladores confunde >> com a operação

    vector<pair<int, int>> pontos = {{1, 2}, {1, 1}, {3, 4}};
    sort(pontos.begin(), pontos.end());  // Ordena pelo first e desempata pelo second
    for (auto i : pontos) {
        printf("(%d, %d) ", i.first, i.second);
    }
    cout << endl;
}
