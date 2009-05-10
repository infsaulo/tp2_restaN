#ifndef METRICA
#define METRICA

/*
 Descrição:
 Metrica.h define o TAD Metrica, que representa a métrica utilizada para selecionar
 as melhores escolhas nas jogadas.

 Autor:
 Saulo Marques Ribeiro Ricci

 Data:
 06/05/2009
*/

// Referências necessárias
#include "../ListaSnap/ListaSnap.h"

// Estrutura de dados que define um Ranking
typedef struct Ranking
{
	// Snapshot que está numa determinada posição do ranking
	Snapshot* snapshot;

	// A pontuação do Snapshot
	short pontuacao;
}Ranking;

// Funções do TAD Ranking

/*
 Inicializa o Ranking apontado pelo primeiro parâmetro com o Snapshot apontado pelo
 segundo parâmetro e com a sua pontuação passada pelo terceiro parâmetro.
*/
void inicializaRanking(Ranking* ranking, Snapshot* snapshot, short pontuacao);

/*
 Copia os dados do Ranking apontado pelo segundo parâmetro para o Ranking apontado
 pelo primeiro parâmetro.
*/
void copiaRanking(Ranking* ranking1, Ranking* ranking2);

/*
 Libera espaco de memória alocada para o Ranking apontado pelo parâmetro.
*/
void liberaEspacoRanking(Ranking* ranking);

// Estrutura de dados Metrica
typedef struct Metrica
{
	// Apontador para um vetor de Ranking
	Ranking* vetorRanking;
	
	// Quantidade de Elementos que estão no vetor
	short quantidadeElementos;
}Metrica;

// Operações sobre o TAD Metrica

/*
 Inicializa a Metrica apontada pelo primeiro parâmetro com os dados da ListaSnap
 apontada pelo segundo parâmetro.
*/
void inicializaMetrica(Metrica* metrica, ListaSnap* lista);

/*
 Aplica a a função da Metrica apontada pelo parâmetro.
*/
void aplicaMetrica(Metrica* metrica, ListaSnap* lista);

/*
 Retorna a referência para o Snapshot mais promissor segundo a função da métrica 
 utilizada.
*/
Snapshot* retornaMelhorSnapshotRankingMetrica(Metrica* metrica);

/*
 Função que ordena o Ranking da Metrica apontada pelo parâmetro, utilizando a 
 chave de ordenação o campo pontuacao do TAD Ranking. O método de ordenação 
 utilizado é HeapSort.
*/
void ordenaRankingMetrica(Metrica* metrica);

/*
 Libera espaço de memória alocada para a Metrica apontada pelo parâmetro.
*/
void liberaEspacoMetrica(Metrica* metrica);

#endif
