#ifndef SNAPSHOT
#define SNAPSHOT

/*
 Snapshot.h define a interface do TAD Snapshot, que representa um estado do jogo
 ao longo de todas as jogadas possíveis.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 02/05/2009
*/

// Referências necessárias
#include "../Tabuleiro/Tabuleiro.h"
#include "../FilaPos/FilaPos.h"
#include "../PilhaMov/PilhaMov.h"

// Estrutura de dados Snapshot
typedef struct Snapshot
{
	// Tabuleiro do jogo
	Tabuleiro* tabuleiro;
	
	// Fila das posições vazias do Tabuleiro
	FilaPos* posVazias;
	
	// Pilha dos movimentos realizados até chegar na configuração do Tabuleiro atual
	PilhaMov* pilhaMovimentos;
	
}Snapshot;

// Operações sobre o TAD Snapshot

/*
 Inicializa o Snapshot apontado pelo primeiro parâmetro com os dados apontados
 pelos outros parâmetros.
*/
void inicializaSnapshot(Snapshot* snap, Tabuleiro* tabuleiro, FilaPos* fila, PilhaMov* pilha);

/*
 Acrescenta um movimento para o Snapshot apontado pelo primeiro parâmetro. O novo
 movimento é apontado pelo segundo parâmetro.
*/
void acrescentaMovimentoSnapshot(Snapshot* snap, Movimento* movimento);

/*
 Copia os dados do Snapshot apontado pelo segundo parâmetro para o Snapshot 
 apontado pelo primeiro parâmetro.
*/
void copiaSnapshot(Snapshot* snap1, Snapshot* snap2);

/*
 Retorna uma referência para o Tabuleiro do Snapshot apontado pelo parâmetro.
*/
Tabuleiro* retornaTabuleiroSnapshot(Snapshot* snap);

/*
 Retorna uma referência para a Fila de Posições Vazias do Snapshot apontado pelo
 pelo parâmetro.	
*/
FilaPos* retornaFilaPosSnapshot(Snapshot* snap);

/*
 Retorna uma referência para a Pilha de Movimentos do Snapshot apontado pelo 
 parâmetro.
*/
PilhaMov* retornaPilhaMovSnapshot(Snapshot* snap);

/*
 Libera espaço de memória alocado para o Snapshot apontado pelo parâmetro.
*/
void liberaEspacoSnapshot(Snapshot* snap);

#endif

