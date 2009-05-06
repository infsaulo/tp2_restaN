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
#include "../IO/io.h"

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
	
	PilhaMov* pilhaVazia = (PilhaMov*)calloc(1, sizeof(pilhaVazia));
	inicializaPilhaMov(pilhaVazia);
	
	// Procura por possições vazias
	FilaPos* posVazias = retornaPosVaziasTabuleiro(tabuleiro);
	
	inicializaSnapshot(jogo->atual, tabuleiro, posVazias, pilhaVazia);
	
	liberaEspacoTabuleiro(tabuleiro);
	liberaEspacoPilhaMov(pilhaVazia);
	liberaEspacoFilaPos(posVazias);
}

/*
 Operação que realiza, no máximo, K-jogadas por rodada, onde, no final de cada 
 rodada é aplicada uma métrica de decisão da melhor configuração. O jogo é 
 apontado pelo parâmetro.
 As rodadas continuarão até que não haja possibilidade de mais nenhuma jogada.
*/
void jogar(Jogo* jogo)
{

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
