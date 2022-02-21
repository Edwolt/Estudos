#include <bits/stdc++.h>
using namespace std;

void construtores() {
    int n = 10;
    vector<int> v1;                                 //
    vector<int> v2(n);                              // v2 tem tamanho n
    vector<int> v3(n, 0);                           // v3 tem n posições com valor 0
    vector<int> v4 = {1, 2, 3, 4};                  //
    vector v4 = {1, 2, 3, 4};                       // Para C++17
    vector<vector<int>> mat(n, vector<int>(n, 0));  // Matriz n por n com tudo igual a zero
}

void iteradores() {
    // Similar a ponteiro para a STL
    // i é um iterador de vetor

    vector<int> v = {1, 2, 3, 4, 5};
    for (auto i = v.begin(); i < v.end(); i++) {  // Não vale para qualquer STL
        cout << *i << " ";
    }
    cout << endl;

    for (auto i = v.begin(); i != v.end(); i++) {  // Vale para qualquer STL
        cout << *i << " ";
    }
    cout << endl;
}

void bound() {
    vector<int> v = {1, 2, 3, 3, 3, 5, 6, 6};
    // Vector precisa esta ordenado
    auto low = lower_bound(v.begin(), v.end(), 3);  // iterador a partir do elemento menor que 3
    auto up = upper_bound(v.begin(), v.end(), 3);   // iterador a partir do elemento maior que 3

    int cont = up - low;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // "for each"
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    v.push_back(1);                         // Insere item no final: O(1)
    v.pop_back();                           // Exclui item do final
    cout << "Back: " << v.back() << endl;   // Retorna o valor da última posição
    cout << "front: " << v.back() << endl;  // Retorna o valor da primeita posição
    v.clear();                              // Deleta todos os dados do vetor
    v.resize(50);                           // Redimensiona vetor
    v.empty();                              // Retorna true se vetor estiver vazio
    // v.insert(...); // O(n)

    // Ordenar
    v.push_back(100);
    v.push_back(3);
    v.push_back(120);
    v.push_back(80);
    v.push_back(-1);

    sort(v.begin(), v.end());  // crescente
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.rbegin(), v.rend());  // decrescente
    for (int x : v) cout << x << " ";
    cout << endl;

    int array[100];  // Ordenando Array
    sort(begin(array), end(array));
    sort(array, array + 100);
}
