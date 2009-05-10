/*
 Descrição:
 Jogo.c implementa as funções cujos protótipos estão definidos no arquivo Jogo.h
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 05/05/2009
*/

// Bibliotecas e referências necessárias
#include <stdlib.h>
#include "Jogo.h"
#include "../../IO/io.h"
#include "../Metrica/Metrica.h"

/*
 Inicializa o Jogo apontado pelo primeiro parâmetro, com o nível passado pelo 
 terceiro parâmetro. O nome do arquivo de configuração inicial do Tabuleiro é 
 apontado pelo segundo parâmetro.
*/
void inicializaJogo(Jogo* jogo, char* nomeArquivo, short nivel)
{
	jogo->atual = (Snapshot*)calloc(1, sizeof(Snapshot));
	
	Tabuleiro* tabuleiro = (Tabuleiro*)calloc(1, sizeof(Tabuleiro));
	inicializaTabuleiro(tabuleiro, nomeArquivo);
	
	PilhaMov* pilhaVazia = (PilhaMov*)calloc(1, sizeof(PilhaMov));
	inicializaPilhaMov(pilhaVazia);
	
	// Procura por possições vazias
	FilaPos* posVazias = retornaPosVaziasTabuleiro(tabuleiro);
	
	inicializaSnapshot(jogo->atual, tabuleiro, posVazias, pilhaVazia);
	
	liberaEspacoTabuleiro(tabuleiro);
	liberaEspacoPilhaMov(pilhaVazia);
	liberaEspacoFilaPos(posVazias);
	
	jogo->nivel = nivel;
}

/*
 Operação que realiza, no máximo, K-jogadas por rodada, onde, no final de cada 
 rodada é aplicada uma métrica de decisão da melhor configuração. O jogo é 
 apontado pelo parâmetro.
 As rodadas continuarão até que não haja possibilidade de mais nenhuma jogada.
*/
void jogar(Jogo* jogo)
{
	// ListaSnap pai
	ListaSnap* pai = (ListaSnap*)calloc(1, sizeof(ListaSnap));
	inicializaListaSnap(pai, 0);
	acrescentaSnapshotListaSnap(pai, jogo->atual);
	
	short nivelJogada = 1;
	
	/*
	 ListaSnap derivada da ListaSnap pai. Retrata todos os Snapshots possíveis para
	 a próxima jogada.
	*/
	ListaSnap* filha = geraListaSnapDerivada(pai);
	
	// Laço para as próximas jogadas até finalizar o jogo.
	while(!listaSnapVazia(filha))
	{
		// Realiza no máximo k jogadas e recolhe o Snapshot mais promissor
		while((nivelJogada < jogo->nivel) && (!listaSnapVazia(filha)))
		{
			liberaEspacoListaSnap(pai);
			pai = (ListaSnap*)calloc(1, sizeof(ListaSnap));
			copiaListaSnap(pai, filha);
			liberaEspacoListaSnap(filha);
			filha = geraListaSnapDerivada(pai);
			nivelJogada++;
		}
		
		if(!listaSnapVazia(filha))
		{
			Metrica* metrica = (Metrica*)calloc(1, sizeof(Metrica));
			inicializaMetrica(metrica, filha);
			
			// Melhor Snapshot para o final da rodada de no máximo k jogadas
			Snapshot* melhor = (Snapshot*)calloc(1, sizeof(Snapshot));
			copiaSnapshot(melhor, retornaMelhorSnapshotRankingMetrica(metrica));
			liberaEspacoSnapshot(jogo->atual);
			jogo->atual = (Snapshot*)calloc(1, sizeof(Snapshot));
			copiaSnapshot(jogo->atual, melhor);
			
			liberaEspacoMetrica(metrica);
			liberaEspacoSnapshot(melhor);
		}
		
		// Ultimas jogadas
		else
		{
			Metrica* metrica = (Metrica*)calloc(1, sizeof(Metrica));
			inicializaMetrica(metrica, pai);
			
			// Melhor Snapshot para o final da rodada de no máximo k jogadas
			Snapshot* melhor = (Snapshot*)calloc(1, sizeof(Snapshot));
			copiaSnapshot(melhor, retornaMelhorSnapshotRankingMetrica(metrica));
			liberaEspacoSnapshot(jogo->atual);
			jogo->atual = (Snapshot*)calloc(1, sizeof(Snapshot));
			copiaSnapshot(jogo->atual, melhor);
			
			liberaEspacoMetrica(metrica);
			liberaEspacoSnapshot(melhor);
			liberaEspacoListaSnap(filha);
			liberaEspacoListaSnap(pai);
			
			// Finaliza aqui o jogo
			return;
		}
		
		// Reinicia mais uma nova rodada de no máximo k jogadas.
		liberaEspacoListaSnap(filha);
		liberaEspacoListaSnap(pai);
		nivelJogada = 1;
		pai = (ListaSnap*)calloc(1, sizeof(ListaSnap));
		inicializaListaSnap(pai, 0);
		acrescentaSnapshotListaSnap(pai, jogo->atual);
		filha = geraListaSnapDerivada(pai);
	}
	
	// Pega o melhor Snapshot da ListaSnap pai na finalização do jogo
	Metrica* metrica = (Metrica*)calloc(1, sizeof(Metrica));
	inicializaMetrica(metrica, pai);
	
	// Melhor Snapshot possível
	Snapshot* melhor = (Snapshot*)calloc(1, sizeof(Snapshot));
	copiaSnapshot(melhor, retornaMelhorSnapshotRankingMetrica(metrica));
	liberaEspacoSnapshot(jogo->atual);
	jogo->atual = (Snapshot*)calloc(1, sizeof(Snapshot));
	copiaSnapshot(jogo->atual, melhor);
	
	liberaEspacoListaSnap(pai);
	liberaEspacoListaSnap(filha);
	liberaEspacoMetrica(metrica);
	liberaEspacoSnapshot(melhor);
}

/*
 Escreve os passos realizados até o final do Jogo. O Jogo é apontado pelo primeiro
 parâmetro e o nome do arquivo onde os passos serão armazenados é apontado pelo
 segundo parâmetro.
*/
void escrevePassosJogo(Jogo* jogo, char* nomeArquivo)
{
	escreveMovimentosJogadas(jogo->atual->pilhaMovimentos, jogo->atual->tabuleiro, nomeArquivo);
}

/*
 Libera espaço de memória destinada para o Jogo apontado pelo parâmetro.
*/
void liberaEspacoJogo(Jogo* jogo)
{
	liberaEspacoSnapshot(jogo->atual);
	free(jogo);
}
