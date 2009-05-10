#ifndef ORDENACAO
#define ORDENACAO

/*
 Descrição:
 Ordenacao.h define os protótipos das funções que ordenam o vetor de Ranking, 
 com a chave pontuacao de forma decrescente. A metodologia utilizada é a do 
 HeapSort.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 06/05/2009
*/

// Referências necessárias
#include "../Metrica.h"

/*
 Refaz a condição de heap no vetor de Ranking apontado pelo terceiro parâmetro.
 O inteiro do primeiro parâmetro referencia a posição do nó pai e o inteiro 
 passado pelo segundo parâmetro indica o último nó do heap.
*/
void refaz(int father, int last, Ranking* rankings);

/*
 Contrói a condição de heap do array de Rankings apontado pelo primeiro parâmetro
 cujo tamanho é apontado pelo segundo parâmetro.
*/
void constroi(Ranking* rankings, int* n);

/*
 Ordena o vetor de Ranking passado pelo primeiro parâmetro, conforme o processo
 de heapSort. O segundo parâmetro passado é o tamannho do array.
*/
void heapsort(Ranking* rankings, int quantidade);

#endif

