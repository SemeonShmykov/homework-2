# homework-2
Преобразует файл matr.txt в graph.txt при помощи CreateGraph.c.
Содержимое graph.txt используется для построения графа на https://dreampuf.github.io/

Граф по заданной матрице инцидентности:
 abcdefghi
1101001000
2110000000
3001100000
4000110000
5000001111
6010000100
7000100010
8000000001

graph T {
1 -- 2[label="a"]
2 -- 6[label="b"]
1 -- 3[label="c"]
3 -- 7[label="d"]
4 -- 4[label="e"]
1 -- 5[label="f"]
5 -- 6[label="g"]
5 -- 7[label="h"]
5 -- 8[label="i"]
}

https://bit.ly/3ACDJhb
