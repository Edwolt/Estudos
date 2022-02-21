#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> st;
    st.insert(5);  // {5}
    st.insert(2);  // {2, 5}
    st.insert(1);  // {1, 2, 5}
    st.insert(2);  // {1, 2, 5}
    st.insert(6);  // {1, 2, 5, 6}

    int x = 100;
    set<int>::iterator it = st.find(x);  // Verifica se x está no set
    if (it == st.end()) {
        cout << x << " não está no set" << endl;
    }

    int x = 6;
    auto it = st.find(x);  // Verifica se x está no set
    if (it == st.end()) {
        cout << x << " não está no set" << endl;
    }

    x = 6;
    st.erase(x);  // tira x do set

    for (auto i = st.begin(); i != st.end(); i++) {  // Printa todos os valores do set
        cout << *i << " ";
    }
    cout << endl;

    for (auto j : st) {  // Printa todos os valores do set
        cout << j << " ";
    }
    cout << endl;
}
