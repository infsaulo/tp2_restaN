/*
 Descrição:
 Metrica.c implementa as operações do TAD Metrica e as operações das funções das
 estruturas auxiliares.

 Autor:
 Saulo Marques Ribeiro Ricci

 Data:
 06/05/2009
*/

// Bibliotecas e referências necessárias
#include <stdlib.h>
#include "Metrica.h"
#include "Ordenacao/Ordenacao.h"

/*
 Inicializa o Ranking apontado pelo primeiro parâmetro com o Snapshot apontado pelo
 segundo parâmetro e com a sua pontuação passada pelo terceiro parâmetro.
*/
void inicializaRanking(Ranking* ranking, Snapshot* snapshot, short pontuacao)
{
	ranking->snapshot = (Snapshot*)calloc(1, sizeof(Snapshot));
	copiaSnapshot(ranking->snapshot, snapshot);

	ranking->pontuacao = pontuacao;
}

/*
 Copia os dados do Ranking apontado pelo segundo parâmetro para o Ranking apontado
 pelo primeiro parâmetro.
*/
void copiaRanking(Ranking* ranking1, Ranking* ranking2)
{
	ranking1->snapshot = (Snapshot*)calloc(1, sizeof(Snapshot));
	copiaSnapshot(ranking1->snapshot, ranking2->snapshot);
	ranking1->pontuacao = ranking2->pontuacao;
}

/*
 Libera espaco de memória alocada para o Ranking apontado pelo parâmetro.
*/
void liberaEspacoRanking(Ranking* ranking)
{
	liberaEspacoSnapshot(ranking->snapshot);

	free(ranking);
}

/*
 Inicializa a Metrica apontada pelo primeiro parâmetro com os dados da ListaSnap
 apontada pelo segundo parâmetro.
*/
void inicializaMetrica(Metrica* metrica, ListaSnap* lista)
{
	metrica->quantidadeElementos = lista->quantidadeSnaps;
	
	metrica->vetorRanking = (Ranking*)calloc(metrica->quantidadeElementos, sizeof(Ranking));
	
	// Computa o Ranking conforme a função da Metrica utilizada.
	aplicaMetrica(metrica, lista);
}

/*
 Aplica a a função da Metrica apontada pelo parâmetro.
*/
void aplicaMetrica(Metrica* metrica, ListaSnap* lista)
{
	// Povoa o vetor de Ranking.
	apontaPrimeiroListaSnap(lista);
	
	int iterator = 0;
	Snapshot* snap = retornaSnapshotListaSnap(lista);
	
	while(snap != NULL)
	{
		inicializaRanking(&metrica->vetorRanking[iterator], snap, 
			retornaQuantidadeMovimentacoesPossiveisTabuleiro(snap->tabuleiro));
		snap = retornaSnapshotListaSnap(lista);
		iterator++;
	}
	
	// Ordena o vetor de Rankings conforme o modelo HeapSort
	ordenaRankingMetrica(metrica);
	
	apontaPrimeiroListaSnap(lista);
}

/*
 Retorna a referência para o Snapshot mais promissor segundo a função da métrica 
 utilizada.
*/
Snapshot* retornaMelhorSnapshotRankingMetrica(Metrica* metrica)
{
	return metrica->vetorRanking[metrica->quantidadeElementos - 1].snapshot;
}

/*
 Função que ordena o Ranking da Metrica apontada pelo parâmetro, utilizando a 
 chave de ordenação o campo pontuacao do TAD Ranking. O método de ordenação 
 utilizado é HeapSort.
*/
void ordenaRankingMetrica(Metrica* metrica)
{
	// Ordena o vetor de Ranking conforme o HeapSort
	heapsort(metrica->vetorRanking, metrica->quantidadeElementos);
}

/*
 Libera espaço de memória alocada para a Metrica apontada pelo parâmetro.
*/
void liberaEspacoMetrica(Metrica* metrica)
{
	int iterator;
	
	for(iterator = 0; iterator < metrica->quantidadeElementos; iterator++)
	{
		liberaEspacoSnapshot(metrica->vetorRanking[iterator].snapshot);
	}
	
	free(metrica->vetorRanking);
	free(metrica);
}

