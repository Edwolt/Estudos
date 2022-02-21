#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> pilha;

    pilha.push(1);  // Coloca o valor no topo da pilha
    pilha.pop();    // Tira o valor do topo da pilha
    pilha.top();    // Retorna valor no topo da pilha
    pilha.empty();  // Retorna true se a pilha estiver vazia

    while (!pilha.empty()) {
        int n = pilha.top();
        pilha.pop();

        /* Código */
        cout << n << " ";
    }
    cout << endl;
}
