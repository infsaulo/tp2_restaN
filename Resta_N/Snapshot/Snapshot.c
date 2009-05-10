/*
 Descrição:
 Snapshot.c implementa as operações sobre o TAD Snapshot.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 02/05/2009
*/

// Bibliotecas necessárias
#include <stdlib.h>
#include "Snapshot.h"

/*
 Inicializa o Snapshot apontado pelo primeiro parâmetro com os dados apontados
 pelos outros parâmetros.
*/
void inicializaSnapshot(Snapshot* snap, Tabuleiro* tabuleiro, FilaPos* fila, PilhaMov* pilha)
{
	snap->tabuleiro = (Tabuleiro*)calloc(1, sizeof(Tabuleiro));
	copiaTabuleiro(snap->tabuleiro, tabuleiro);
	
	snap->posVazias = (FilaPos*)calloc(1, sizeof(FilaPos));
	inicializaFilaPos(snap->posVazias);
	copiaFilaPos(snap->posVazias, fila);
	
	snap->pilhaMovimentos = (PilhaMov*)calloc(1, sizeof(PilhaMov));
	inicializaPilhaMov(snap->pilhaMovimentos);
	copiaPilhaMov(snap->pilhaMovimentos, pilha);
}

/*
 Acrescenta um movimento para o Snapshot apontado pelo primeiro parâmetro. O novo
 movimento é apontado pelo segundo parâmetro.
*/
void acrescentaMovimentoSnapshot(Snapshot* snap, Movimento* movimento)
{
	// Desenfileira a posição vazia da Fila de Posições vazias do snapshot
	desenfileiraFilaPos(snap->posVazias);
	
	// Modifica o Tabuleiro conforme o movimento passado pelo parâmetro.
	modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
	retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)), OCUPADA);
	
	Posicao* restante1 = (Posicao*)calloc(1, sizeof(Posicao));
	Posicao* restante2 = (Posicao*)calloc(1, sizeof(Posicao));
	Posicao* posEmpilhada = (Posicao*)calloc(1, sizeof(Posicao));
	Movimento* movimentoEmpilhado = (Movimento*)calloc(1, sizeof(Movimento));
	switch(retornaMovimentacaoMovimento(movimento))
	{
		// Movimentação do pino para cima
		case BAIXO:
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)), VAZIA);
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)), VAZIA);
			inicializaPosicao(restante1, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			enfileiraFilaPos(snap->posVazias, restante1);
			inicializaPosicao(restante2, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			enfileiraFilaPos(snap->posVazias, restante2);
			
			// Acrescenta o movimento na Fila de Movimentos
			inicializaPosicao(posEmpilhada, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			inicializaMovimento(movimentoEmpilhado, posEmpilhada, BAIXO);
			empilhaPilhaMov(snap->pilhaMovimentos, movimentoEmpilhado);
			break;
		
		// Movimetação do pino para esquerda
		case DIREITA:
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2, VAZIA);
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1, VAZIA);
			inicializaPosicao(restante1, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1);
			enfileiraFilaPos(snap->posVazias, restante1);
			inicializaPosicao(restante2, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2);
			enfileiraFilaPos(snap->posVazias, restante2);
			
			// Acrescenta o movimento na Fila de Movimentos
			inicializaPosicao(posEmpilhada, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2);
			inicializaMovimento(movimentoEmpilhado, posEmpilhada, DIREITA);
			empilhaPilhaMov(snap->pilhaMovimentos, movimentoEmpilhado);
			break;
		
		// Movimentação do pino para baixo
		case CIMA:
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)), VAZIA);
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)), VAZIA);
			inicializaPosicao(restante1, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			enfileiraFilaPos(snap->posVazias, restante1);
			inicializaPosicao(restante2, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			enfileiraFilaPos(snap->posVazias, restante2);
			
			// Acrescenta o movimento na Fila de Movimentos
			inicializaPosicao(posEmpilhada, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2,
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)));
			inicializaMovimento(movimentoEmpilhado, posEmpilhada, CIMA);
			empilhaPilhaMov(snap->pilhaMovimentos, movimentoEmpilhado);
			break;
		
		// Movimentação do pino para direita
		default:
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2, VAZIA);
			modificaEstadoPosicaoTabuleiro(snap->tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1, VAZIA);
			inicializaPosicao(restante1, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1);
			enfileiraFilaPos(snap->posVazias, restante1);
			inicializaPosicao(restante2, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2);
			enfileiraFilaPos(snap->posVazias, restante2);
			
			// Acrescenta o movimento na Fila de Movimentos
			inicializaPosicao(posEmpilhada, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
				retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2);
			inicializaMovimento(movimentoEmpilhado, posEmpilhada, ESQUERDA);
			empilhaPilhaMov(snap->pilhaMovimentos, movimentoEmpilhado);
			break;
	}
	
	liberaEspacoPosicao(restante1);
	liberaEspacoPosicao(restante2);
	liberaEspacoPosicao(posEmpilhada);
	liberaEspacoMovimento(movimentoEmpilhado);
}

/*
 Copia os dados do Snapshot apontado pelo segundo parâmetro para o Snapshot 
 apontado pelo primeiro parâmetro.
*/
void copiaSnapshot(Snapshot* snap1, Snapshot* snap2)
{
	snap1->tabuleiro = (Tabuleiro*)calloc(1, sizeof(Tabuleiro));
	copiaTabuleiro(snap1->tabuleiro, snap2->tabuleiro);
	
	snap1->posVazias = (FilaPos*)calloc(1, sizeof(FilaPos));
	inicializaFilaPos(snap1->posVazias);
	copiaFilaPos(snap1->posVazias, snap2->posVazias);
	
	snap1->pilhaMovimentos = (PilhaMov*)calloc(1, sizeof(PilhaMov));
	inicializaPilhaMov(snap1->pilhaMovimentos);
	copiaPilhaMov(snap1->pilhaMovimentos, snap2->pilhaMovimentos);
}

/*
 Retorna uma referência para o Tabuleiro do Snapshot apontado pelo parâmetro.
*/
Tabuleiro* retornaTabuleiroSnapshot(Snapshot* snap)
{
	return snap->tabuleiro;
}

/*
 Retorna uma referência para a Fila de Posições Vazias do Snapshot apontado pelo
 pelo parâmetro.	
*/
FilaPos* retornaFilaPosSnapshot(Snapshot* snap)
{
	return snap->posVazias;
}

/*
 Retorna uma referência para a Pilha de Movimentos do Snapshot apontado pelo 
 parâmetro.
*/
PilhaMov* retornaPilhaMovSnapshot(Snapshot* snap)
{
	return snap->pilhaMovimentos;
}

/*
 Libera espaço de memória alocado para o Snapshot apontado pelo parâmetro.
*/
void liberaEspacoSnapshot(Snapshot* snap)
{
	liberaEspacoTabuleiro(snap->tabuleiro);
	liberaEspacoFilaPos(snap->posVazias);
	liberaEspacoPilhaMov(snap->pilhaMovimentos);
	free(snap);
}

