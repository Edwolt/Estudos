# Divisores
### Divisores de um número
- Como $`n=\sqrt n \sqrt n`$, cada divisor menor que $`\sqrt n`$ tem seu correspondente maior que $`\sqrt n`$;
- Complexidade: $`O(\sqrt n)`$

### Divisores Primos

### MMC e MDC

### Crivo Eratóstenes
- Complexidade: $`O(\ln{x})`$

### Verificar Primo
- Complexidade: $`O(n \log (\log (n)))`$

# Formulas úteis

- A soma a seguir sempre tem formula fechada

```math
\sum^n_{x=1} x^k = 1^k + 2^k + 3^k + ... + n^k
```

- Progressão aritmética: A soma das pontas sempre dão igual
```math
S_n = \frac {n (a_1 + a_n)} {2}
```
Onde $`S_n`$ é as soma dos n primeiros termos

- Prograssão geométrica
```math
S_n = \frac {a_1 (q^n -1 )} {q - 1} \
S_\infty = \frac {a_1} {1 - q}
```
Onde $`q`$ é a razão da progressão

- Soma harmônica tem lowerbound de $`log_2(n) + 1`$
```math
\sum^n_{x=1} \frac 1 x = 1 + \frac 1 2 + \frac 1 3 + ... + \frac 1 n
```
