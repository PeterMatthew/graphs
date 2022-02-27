# graphs

## Como usar

### dijkstra
```console
cd dijkstra
```
```console
make dijkstra
```
Menor distância entre o vértice 1 e o vértice 5
```console
./dijkstra -i 1 -l 5 < input.txt
```
Imprime a distância do vértice inicial 1 até os demais
```console
./dijkstra -i 1 < input.txt
```

### bellman ford
```console
cd bellman_ford
```
```console
make bellman_ford
```
Menor distância entre o vértice 1 e o vértice 5
```console
./bellman_ford -i 1 -l 5 < input.txt
```
Imprime a distância do vértice inicial 1 até os demais
```console
./bellman_ford -i 1 < input.txt
```

### prim
```console
cd prim
```
```console
make prim
```
Calcula o custo da AGM com vértice inicial 1
```console
./prim -i 1 < input.txt
```
Imprime a árvore com vértice inicial 1
```console
./prim -s -i 1 < input.txt
```

### kruskal
```console
cd kruskal
```
```console
make kruskal
```
Calcula o custo da AGM
```console
./kruskal < input.txt
```
Imprime a árvore
```console
./kruskal -s < input.txt
```
