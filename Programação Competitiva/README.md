# Índice
- Fibonacci: Várias implementações para encontrar o valor de uma posição na sequência de Fibonacci
- String: Alguns exemplos de questões envolvendo strings (como palíndromo)
- Recursão: Contém alguns algoritmos que usam recursão
- STL: Explica como funciona alguns dos contêineres presente na Standad Template Library do C++ (como pilha e fila)
- Grafo: Alguns algoritmos para representar e manipular grafos
- Range: Algoritmos para fazer rapidamente Range_Query e Range_Update
- Teoria dos Números: Divisores/Primos

# Analise de Complexidade
$`10^8`$ operações por segundo é uma boa aproximação para o número de operações
que o c++ é capaz de fazer por segundo

# Entrada e saída
## Fast Cin Cout
Torna o `cin` e o `cout` um pouco mais rápido desvinculando-os do `scanf` e `printf`

Não pode ser usado junto com o `printf` e `scanf`

O `printf` e `scanf` ainda é mais rápido

```cpp
ios::sync_with_stdio(false);
cin.tie(NULL);
```
## Ler quantidade desconhecida de dados
```cpp
while (cin >> x) {
    // ...
}
```

## Redirecionando arquivo para stdin/stdout
```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

# Precisão Float cout
```cpp
cout << fixed << setprecision(10) << res << endl;
```

# Frequência
Se o importante é saber o número de vezes que um número aparece,
array de frequência é uma boa

Se tiver muitos valores, pode ser necessário usar um map

# Questões com $`10^9+7`$ (Matemática Modular)
Esse número serve para fazer não da overflow\
Use as propiedades:

- `(a+b) % c = a%c + b%c`
- `(a-b) % c = a%c - b%c`
- `(ab) % c = (a%c)(b%c)`
- `(a/b) % c < (a%c)/(b%c)`

# Overflow
Preste atenção que não é necessário que o resultado final exceda o limite para dar overflow\
Se em qualquer parte da com acontecer um overflow O resultado já estará atrapalhado\
(um `int` somado a outro `int` retorna um `int` que se tiver seu valor estourado já atrapalha a conta)

# Infinito
```cpp
#define INF 0x3f3f3f3f
```
`INF` cabe em um `int` e `INF + INF` também

`INF * INF` cabe em um `long`

Dá para usar `memset` com `INF`

# Variaveis Globais
Variaveis globais são incializadas com 0

# Estimando Eficiência
Tentando descobrir a complexidade da solução pelas restriçoes do input

| Tamanho do Input | Complexidade de Tempo       |
|------------------|-----------------------------|
| $`n \le 10`$     | $`O(n!)`$                   |
| $`n \le 20`$     | $`O(2^n)`$                  |
| $`n \le 500`$    | $`O(n^3)`$                  |
| $`n \le 5000`$   | $`O(n^2)`$                  |
| $`n \le 10^6`$   | $`O(n log(n))`$ or $`O(n)`$ |
|                  | $`O(1)`$ or $`O(log(n))`$   |

# Iteradores
```cpp
sort(vec.begin(), vec.end())
sort(array, array + n)

sort(vec.begin(), vec.end(), func)

// Não esqueça de sortings alternativos, como counting sort

reverse(vec.begin(), vec.end())
random_shuffle(vec.begin(), vec.end())
```

# Gerando permutações
- Subsets:
```cpp
void search(int i) {
    // i não faz parte
    search(i+1);

    // i faz parte
    add i+1 to subset
    search(i+1);
    pop i+1 to subset
}

// Ou usar int para iterar sobre subsets
```
- Permutações:
```cpp
sort(vec.begin(), vec.end());

do {
// process permutation
} while (next_permutation(vec.begin(), vec.end()));
```
