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
