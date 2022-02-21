#include <bits/stdc++.h>
using namespace std;

struct comparar {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

struct Struct {
    int a;
    int b;

    bool operator<(const Struct& that) const {
        return (this->a * this->b + this->a) > (that.a * that.b - that.a);
    }
};

int main() {
    priority_queue<int> pq;
    pq.push(5);  // Insere elemento
    pq.push(10);
    pq.push(1);

    pq.top();  // Retorna valor do maior elemento em O(1)
    pq.pop();  // Remove maior elemento

    // Ordenando por função arbitraria
    priority_queue<int, vector<int>, comparar> pqc;
    pqc.push(10);

    priority_queue<Struct> pqs;
    pqs.push({1, 1});
    pqs.push({100, 100});
    pqs.push({0, 0});
}
