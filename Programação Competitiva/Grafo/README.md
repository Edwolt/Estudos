# Visitar Vértices
- DFS (Busca por profundidade)
    - Recursão: vai até o nó mais profundo e depois volta fazendo o mesmo para os outros
    - Bom para encontrar componentes conexas
    - Complexidade: $`O(n+m)`$ com n igual ao número de vertices e m igual ao número de arestas

- BFS (Busca em largura)
    - Visita todos os nós adjacentes antes de ir para os mais profundos
    - Bom para encontrar distâncias


# Arestas com peso
- Dijkstra
    - Calcula o peso para chegar em determinado nó
    - Parecido com a BFS, porém usa fila de prioridade

# MST (Árvore Geradora Miníma)
- Prim
    - Adiciona sempre a aresta de menor valor ao grafo que já faz parte da componente que faz parte
    - Não funciona com grafo direcionados

- Kruskal
    - Cada vértice começa sendo uma sub-árvores, e a cada iteração é adicionados todas as arestas com menor valor

- Boruvka
    - Consegue mexer com pesos negativos
    - (Tem uma implementação muito difícil, por isso não está aqui)
