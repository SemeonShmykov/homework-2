#include <stdio.h>
#include <string.h>

const int nodeMax = 100;//(макс -1) допустимое кол во узлов в графе
const int edgeMax = 100;//(макс -1) допустимое кол во ребер в графе

struct Edge //структура для хранения ребра графа
{
    char name;//имя ребра (идентификатор) 
    char node1, node2; //имена узлов кот принадл данному ребру 
};
int main()
{
    int i=0, k = 0;
    int numberNodes;// кол во узлов в графе
    FILE* fin;
    fin = fopen("C:\\Users\\semas\\source\\repos\\h2\\h2\\matr.txt", "r");
    char str[nodeMax][edgeMax];
    // считываем граф из файла
    while (NULL != fgets(str[i++], 100, fin)) {
        printf("%s ", str[i-1]);
    }
    fclose(fin);
    numberNodes = i - 2;//кол во узлы в графе равно кол ву считаных из файла строк -2
    //т.к на 0ой строке идентификаторы ребер а i увеличилось на 1 на последн итерации цикла считывания
    //str[0] содержит идентификаторы ребер и 0ой пробел
    // в остальных строках информация по узлам графа. 0ая буква - идентиф-р узла
    // последующие символы - 0 или 1 значат принадлежит ли узел ребру с порядковым номером 
    // таким же как и положение этого знака(0 или 1)
    // кол во ребер в графе такое же как букв в 0ой строке -1

    // выделяем память под ребра
    int numberEdges=strlen(str[0]) - 1;
    Edge* edges = new Edge[numberEdges];
    // заполняем ребра значениями
    for (i = 0; i < numberEdges; i++) {
        edges[i].name = str[0][i + 1];// самый 1ый симв пробел поэтому i+1
        // заполняем пробелами чтобы в конечн обаботке исключить ошибочно заполненные ребра без вершин
        edges[i].node1 = ' '; 
        edges[i].node2 = ' ';
        //сканируем столбец i+1 чтобы найти сначала 1ый узел ребра потом 2ой
        for (int j = 0, node1found = 0; j <= numberNodes; j++) {
            if (str[j+1][i+1] == '1')
                if (node1found == 0) {
                    edges[i].node1 = str[j + 1][0];
                    edges[i].node2 = str[j + 1][0];// для случая с одной единицей в столбце (петля)
                    node1found++;
                }
                else
                {
                    edges[i].node2 = str[j + 1][0];
                }                   
        }
    }
    FILE* fout;
    fout = fopen("C:\\Users\\semas\\source\\repos\\h2\\h2\\graph.txt", "w");
    fprintf(fout, "graph T {\n");
    //распечатываем массив с ребрами
    for (i = 0; i < numberEdges; i++)
        if (edges[i].name!='\n')fprintf(fout, "%c -- %c[label=\"%c\"]\n", edges[i].node1, edges[i].node2, edges[i].name);
    fprintf(fout, "}\n");
}
