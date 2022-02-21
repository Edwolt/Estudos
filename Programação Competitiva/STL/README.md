# Template
Permite usar uma mesma sequência de passos para vários tipos diferentes de dados

O compilador está criando uma função nova toda vez que usamos tipos diferentes no template


# Standard Template Library
### Vector
- Acesso $O(1)$
- tamanho modificável
- coloca e tira do final em $O(1)$

### Pilha
- O último a ser empilhado é o primeiro a sair
- É um "vetor" que não pode ser alterado no meio
- Tira e coloca do topo em $O(1)$
- Obs: Toda recursão pode ser escrita em forma de pilha, na verdade a recursão é uma pilha

### Fila
- Quem chega primeiro sai primeiro
- É um "vetor" que não pode ser alterado no meio
- Tira do inicio e coloca no final em $O(1)$

### Deque (Double ended queue)
- Tanto fila quanto pilha
- Tira e coloca no inicio e no final em $O(1)$
- Diferentemente do vector a inserção no inicio é $O(1)$ e não $O(n)$

### Par
Associa dois valores

### Set
- Representa um conjunto em que não há item repetido; inserir/remover/buscar é $O(\log (n))$
- Está sempre ordenado

### Fila de Prioridade
- O maior elemento fica na frente
- Acessa primeiro elemento em $O(1)$ e insere em $O(\log (n))$

### Mapa
- Armazena apenas valores das posições necessárias, assim não enche a estrutura com zeros ou valores desnecessários
- Tem uma chave e um valor (organiza em ordem crescente das chaves)
- Suas funções são em $O(\log (n))$
- A chave precisa ter `operator<` definido
- Ótimo para questões de frequência com vetores esparsos, pois vetor de frequência de tamanho $10^{10}$ consome muita memória

### Unordered_set e Unordered_map
- Operações são em $O(1)$
- Usam hash, por isso pode não dar certo em contests com fase de hack


# Iteradores
Disponivel para maioria dos containers do STL\
percorra assim:
```cpp
for(auto i = stl.begin(); i != stl.end(); i++)
{
    *i; // Pega valor para o qual o iterador está apontando
    /* Código */
}
```
Ou assim:
```cpp
for(auto i : stl)
{
    i; // Pega valor para o qual o iterador está apontando
    /* Código */
}
```
Existem também os iteradores reversos (stl.rbegin(), stl.rend()): quando incrementados aponta para posição anterior


# Sort
O `sort` está disponível para qualquer `struct` com a função `operator<` definido
