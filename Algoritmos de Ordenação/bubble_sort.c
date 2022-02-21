#include <stdbool.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int* vet, int n) {
    int i, j;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                swap(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void bubble_sort_aprimorado(int* vet, int n) {
    int i, j;
    bool trocou;
    for (i = n - 1; i > 0; i--) {
        trocou = false;
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                trocou = true;
                swap(&vet[j], &vet[j + 1]);
            }
        }
        if (!trocou) {
            return;
        }
    }
}
