void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heap_rearranja(int* vet, int n, int i) {
    int esq = 2 * i + 1;  // Filho da esquerda
    int dir = 2 * i + 2;  // Filho da direita
    int maior = i;

    // Escolhe o maior valor entr i, esq e dir
    if (esq < n && vet[maior] < vet[esq]) {
        maior = esq;
    }
    if (dir < n && vet[maior] < vet[dir]) {
        maior = dir;
    }

    // Rearranja a Heap se precisar
    if (maior != i) {
        swap(&vet[i], &vet[maior]);
        heap_rearranja(vet, n, maior);
    }
}

void heap_construir(int* vet, int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heap_rearranja(vet, n, i);
    }
}

void heap_sort(int* vet, int n) {
    int i;

    heap_construir(vet, n);
    for (i = n - 1; i > 0; i--) {
        swap(&vet[0], &vet[i]);
        heap_rearranja(vet, i, 0);
    }
}
