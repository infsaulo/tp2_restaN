#ifndef JOGO
#define JOGO

/*
 Descrição:
 Jogo.h define a interface do TAD Jogo.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 05/05/2009
*/

// Referências necessárias
#include "../ListaSnap/ListaSnap.h"
#include "../Snapshot/Snapshot.h"

// Estrutura de dados Jogo
typedef struct Jogo
{
	// Snapshot atual do Jogo
	Snapshot* atual;
	
	// Nível de jogadas que podem ser avaliadas por rodada.
	short nivel;
}Jogo;

// Operações sobre o TAD Jogo

/*
 Inicializa o Jogo apontado pelo primeiro parâmetro, com o nível passado pelo 
 terceiro parâmetro. O nome do arquivo de configuração inicial do Tabuleiro é 
 apontado pelo segundo parâmetro.
*/
void inicializaJogo(Jogo* jogo, char* nomeArquivo, short nivel);

/*
 Operação que realiza, no máximo, K-jogadas por rodada, onde, no final de cada 
 rodada é aplicada uma métrica de decisão da melhor configuração. O jogo é 
 apontado pelo parâmetro.
 As rodadas continuarão até que não haja possibilidade de mais nenhuma jogada.
*/
void jogar(Jogo* jogo);

/*
 Escreve os passos realizados até o final do Jogo. O Jogo é apontado pelo primeiro
 parâmetro e o nome do arquivo onde os passos serão armazenados é apontado pelo
 segundo parâmetro.
*/
void escrevePassosJogo(Jogo* jogo, char* nomeArquivo);

/*
 Libera espaço de memória destinada para o Jogo apontado pelo parâmetro.
*/
void liberaEspacoJogo(Jogo* jogo);

#endif

