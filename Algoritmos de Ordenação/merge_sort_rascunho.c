#include <stdio.h>
#include <stdlib.h>

typedef char byte;

typedef struct _maca
{
    byte tam;
    char cor;
} maca;

typedef maca sort_t;

/**
 * Se a < b então cmp(a, b) < 0
 * Se a = b então cmp(a, b) = 0
 * Se a > b então cmp(a, b) > 0
 */
int cmp(sort_t a, sort_t b)
{
    if (a.cor == b.cor)
    {
        return a.tam - b.tam;
    }
    return a.cor - b.cor;
}

//* ===== Funções Úteis ===== *//

/**
 * Imprimi Conteúdo do vetor
 * Imprime nome para identificar qual vetor está sendo impresso
 */
void imprimir(maca *vet, int n, char *nome)
{
    int i; // Iteradores

    printf("%s\n", nome);
    for (i = 0; i < n; i++)
    {
        printf("[%d,%c] ", vet[i].tam, vet[i].cor);
    }
    printf("\n\n");
}

/**
 * Cria um novo vetor com o mesmo conteúdo de vet
 */
sort_t *copia(sort_t *vet, int n)
{
    int i; // Iteradores
    sort_t *res = (sort_t *)malloc(sizeof(sort_t));
    if (res == NULL)
    {
        return NULL;
    }

    for (i = 0; i < n; i++)
    {
        res[i] = vet[i];
    }
    return res;
}

/**
 * Troca os valores das duas variáveis
 */
void swap(sort_t *a, sort_t *b)
{
    sort_t aux = *a;
    *a = *b;
    *b = aux;
}

//* ===== Merge Sort ===== *//
void merge(sort_t *vet, sort_t *vet_aux, int inicio, int meio, int fim)
{
    int i = inicio;
    int k = inicio;
    int j = meio;

    while (i < meio && j < fim)
    {
        if (cmp(vet[i], vet[j]) < 0)
        {
            vet_aux[k++] = vet[i++];
        }
        else
        {
            vet_aux[k++] = vet[j++];
        }
    }

    while (i < meio)
    {
        vet_aux[k++] = vet[i++];
    }
    while (j < fim)
    {
        vet_aux[k++] = vet[j++];
    }

    for (int i = inicio; i < fim; i++)
    {
        vet[i] = vet_aux[i];
    }
}

void sort(sort_t *vet, sort_t *vet_aux, int inicio, int fim)
{
    if (inicio + 1 >= fim)
    {
        vet_aux[inicio] = vet[inicio];
        return;
    }

    int meio = (inicio + fim) / 2;

    sort(vet, vet_aux, inicio, meio);
    sort(vet, vet_aux, meio, fim);

    merge(vet, vet_aux, inicio, meio, fim);
}

void merge_sort(sort_t *vet, int n)
{
    sort_t *vet_aux = (sort_t *)malloc(n * (sizeof(sort_t)));
    if (vet_aux == NULL)
    {
        printf("Merge Sort Falhou: não foi possivel alocar o vetor");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        vet_aux[i] = vet[i];
    }
    sort(vet, vet_aux, 0, n);

    free(vet_aux);
}

//* ===== Quick Sort ===== *//

void quick_sort(sort_t *vet, int l, int r)
{
    sort_t pivo = vet[(l + r) / 2];

    int i = l;
    int j = r - 1;

    while (i <= j)
    {
        while ((cmp(vet[i], pivo) < 0) && i < r)
        {
            i++;
        }

        while ((cmp(vet[j], pivo) > 0) && j > l)
        {
            j--;
        }

        if (i <= j)
        {
            swap(&vet[i], &vet[j]);
            i++;
            j--;
        }
    }

    if (j > l)
    {
        quick_sort(vet, l, j + 1);
    }

    if (i < r)
    {
        quick_sort(vet, i, r);
    }
}

//* ===== Função Main ===== *//

int main()
{
    int i; // Iteradores
    int n;
    printf("Número de Maçãs: ");
    scanf("%d", &n);

    maca *vet = (maca *)malloc(n * sizeof(maca));

    // Lendo Vetor
    for (i = 0; i < n; i++)
    {
        printf("Maca %d -> tamanho:\t", i + 1);
        scanf(" %hhd", &vet[i].tam);
        printf("Maca %d -> cor:\t", i + 1);
        scanf(" %c", &vet[i].cor);
    }
    printf("\n");

    imprimir(vet, n, "Vetor Original");

    maca *ms = copia(vet, n);
    if (ms == NULL)
    {
        printf("Não foi possível alocar o vetor");
        return EXIT_FAILURE;
    }
    merge_sort(ms, n);
    imprimir(ms, n, "Merge Sort");
    free(ms);

    maca *qs = copia(vet, n);
    if (qs == NULL)
    {
        printf("Não foi possível alocar o vetor");
        return EXIT_FAILURE;
    }
    quick_sort(qs, 0, n);
    imprimir(qs, n, "Quick Sort");
    free(qs);

    free(vet);
}
