#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);  // Coloca item na fila
    q.front();  // Retorna o primeiro item
    q.pop();    // Retira o primeiro item

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        /* Código */
        cout << n << " ";
    }
    cout << endl;
}
