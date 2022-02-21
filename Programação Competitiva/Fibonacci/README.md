# Recursivo
- A função chama ela mesma
- Complexidade: $`O(2^n)`$, se você aproximar que $`f(n)`$ tem mesmo tamanho que $`f(n-1)`$
- Chega ao caso base no mínimo F(n) vezes

# Programação Dinâmica
- Diminuímos o gasto da recursão usando memorização dos estados já alcançados
- É uma recursão, porém os valores que já encontramos é salvo em um array
- Útil para os casos em que não sabemos como sair da implementação recursiva
- Pode ser complicado usar se o array tiver que ser muito grande

- Complexidade: $`O(n + 2n)`$, ou seja $`O(n)`$, pois a complexidade é igual à uma dfs em um grafo (numero de vertices (que a função é executada) + numero de transições(quantas vezes uma função chama outra))

# Iterativa
- Basicamente um for
- Para Fibonacci é fácil fazer isso, mas isso não acontece sempre

- Complexidade: $`O(n)`$

# Matriz
- Se eu encontrar uma matriz $`M`$, quadrada de dimensões $`m`$, para o qual o vetor $`p`$ com os proximo valor é igual a $`p = M * a`$, onde $`a`$ é o vetor com valores atuais
- Eu posso dizer que os valores finais do vetor $`f`$ na $`n`$-esima posição e $`i`$ os valores iniciais, $`f`$ é dado por $`f = M^n * i`$

- Complexidade: $`O(m^3 \log (n))`$, que é o gasto para elevar a matriz a $`n`$
- Formula:
<!--
|F(n)  | = |1  1| |F(n-1)| = |F(n-1) + F(n-2)|
|F(n-1)|   |1  0| |F(n-2)|   |F(n-1)         |

|F(n)  | = |1  1|^n |1| = |a  b| |1|
|F(n-1)|   |1  0|   |1|   |c  d| |1|

F(n) = a + b
-->

```math
\begin{bmatrix}
F(n) \\
F(n-1) \end{bmatrix}
=
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}
\begin{bmatrix}
F(n-1) \\
F(n - 2)
\end{bmatrix}
=
\begin{bmatrix}
F(n-1)\cdot F(n-2) \\
F(n-1)
\end{bmatrix}
```

```math
\Rightarrow
\begin{bmatrix}
F(n) \\
F(n-1)
\end{bmatrix}
=
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}^{n-2}
\begin{bmatrix}
1 \\
1
\end{bmatrix}
=
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}
\begin{bmatrix}
1 \\
1
\end{bmatrix}
```

```math
\Rightarrow
F(n) = a + b
```

# Fórmula
- É muito difícil que essa implementação seja viável durante uma competição, pois requer resolver uma equação de recorrência
- Tendo a fórmula, é possível provar que ela funciona com indução matemática

- Complexidade: $`O(1)`$
- Formula:
<!-- f(n) = (1 / sqrt(5)){[(1 + sqrt(5))/2]^n - [(1 - sqrt(5))/2]^n} -->
```math
f(n) = \frac{1}{\sqrt 5} \left[ \left( \frac{1 + \sqrt 5}{2} \right)^n - \left( \frac{1 - \sqrt 5}{2} \right)^n \right]
```
