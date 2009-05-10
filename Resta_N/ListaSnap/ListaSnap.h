#ifndef LISTASNAP
#define LISTASNAP

/*
 Descrição:
 ListaSnap.h define a interface do TAD que representa uma lista de todos os
 possíveis Snapshots depois de K jogadas.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 03/04/2009
*/

// Referências necessárias
#include "../Snapshot/Snapshot.h"

// Estrutura de dados que define um Snapshot na FilaSnap
typedef struct SnapListado
{
	Snapshot* snapshot;
	struct SnapListado* prox;
}SnapListado;

// Operações sobre o TAD SnapListado

/*
 Inicializa o SnapListado apontado pelo primeiro parâmetro com o Snapshot apontado
 pelo segundo parâmetro.
*/
void inicializaSnapListado(SnapListado* snapListado, Snapshot* snapshot);

/*
 Libera o espaço de memória alocada para o SnapListado apontado pelo parâmetro.
*/
void liberaEspacoSnapListado(SnapListado* snapListado);

// Estrutura de dados que define a Lista de Snapshots
typedef struct ListaSnap
{
	// Lista de Snapshots
	SnapListado* head;
	
	// Nível da jogada que gerou os Snapshots da lista
	short nivel;
	
	// Quantidade de Snapshots que está na ListaSnap
	short quantidadeSnaps;

	SnapListado* posAtual;	
}ListaSnap;

// Operações sobre o TAD ListaSnap

/*
 Inicializa a ListaSnap apontada pelo primeiro parâmetro como vazia e com o nível
 passado pelo segundo parâmetro.
*/
void inicializaListaSnap(ListaSnap* lista, short nivel);

/*
 Acrescenta um Snapshpt na ListaSnap apontada pelo primeiro parâmetro. O Snapshot
 que será acrescentado é apontado pelo primeiro parâmetro.
*/
void acrescentaSnapshotListaSnap(ListaSnap* lista, Snapshot* snap);

/*
 Retorna referência para a ListaSnap derivada da ListaSnap apontada pelo parâmetro.
 Ela representa todos os possíveis Snapshots após uma jogada sobre todos os Snapshots
 da ListaSnap apontada pelo parâmetro.
*/
ListaSnap* geraListaSnapDerivada(ListaSnap* lista);

/*
 Retorna uma referência para o Snapshot apontado pela posição atual da ListaSnap apontada pelo 
 parâmetro.
*/
Snapshot* retornaSnapshotListaSnap(ListaSnap* lista);

/*
 Faz o ponteiro posAtual apontar para o início da ListaSnap apontada pelo parâmetro.
*/
void apontaPrimeiroListaSnap(ListaSnap* lista);

/*
 Retorna 0 se a ListaSnap, apontada pelo parâmetro, não está vazia, ou um outro 
 número caso contrário.
*/
short listaSnapVazia(ListaSnap* lista);

/*
 Copia os dados da ListaSnap apontada pelo segundo parâmetro para a ListaSnap 
 apontada pelo primeiro parâmetro.
*/
void copiaListaSnap(ListaSnap* lista1, ListaSnap* lista2);

/*
 Libera espaço da ListaSnap apontada pelo parâmetro.
*/
void liberaEspacoListaSnap(ListaSnap* lista);

#endif

