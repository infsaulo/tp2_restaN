/*
 Descrição:
 ListaSnap.c implementa as operações do TAD ListaSnap.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 03/05/2009
*/

// Bibliotecas e referências necessárias
#include <stdlib.h>
#include "ListaSnap.h"

/*
 Inicializa o SnapListado apontado pelo primeiro parâmetro com o Snapshot apontado
 pelo segundo parâmetro.
*/
void inicializaSnapListado(SnapListado* snapListado, Snapshot* snapshot)
{
	snapListado->snapshot = (Snapshot*)calloc(1, sizeof(Snapshot));
	copiaSnapshot(snapListado->snapshot, snapshot);
	
	snapListado->prox = NULL;
}

/*
 Libera o espaço de memória alocada para o SnapListado apontado pelo parâmetro.
*/
void liberaEspacoSnapListado(SnapListado* snapListado)
{
	liberaEspacoSnapshot(snapListado->snapshot);
	free(snapListado);
}

/*
 Inicializa a ListaSnap apontada pelo primeiro parâmetro como vazia e com o nível
 passado pelo segundo parâmetro.
*/
void inicializaListaSnap(ListaSnap* lista, short nivel)
{
	lista->head = (SnapListado*)calloc(1, sizeof(SnapListado));
	lista->head->prox = NULL;

	lista->posAtual = lista->head;

	lista->nivel = nivel;	
}

/*
 Acrescenta um Snapshpt na ListaSnap apontada pelo primeiro parâmetro. O Snapshot
 que será acrescentado é apontado pelo primeiro parâmetro.
*/
void acrescentaSnapshotListaSnap(ListaSnap* lista, Snapshot* snap)
{
	SnapListado* novo = (SnapListado*)calloc(1, sizeof(SnapListado));
	inicializaSnapListado(novo, snap);
	
	SnapListado* posIdeal = lista->head;
	while(posIdeal->prox != NULL)
	{
		posIdeal = posIdeal->prox;
	}
	
	posIdeal->prox = novo;
}

/*
 Retorna referência para a ListaSnap derivada da ListaSnap apontada pelo parâmetro.
 Ela representa todos os possíveis Snapshots após uma jogada sobre todos os Snapshots
 da ListaSnap apontada pelo parâmetro.
*/
ListaSnap* geraListaSnapDerivada(ListaSnap* lista)
{
	// ListaSnap de nível superior
	ListaSnap* listaSuperior = (ListaSnap*)calloc(1, sizeof(ListaSnap));
	inicializaListaSnap(listaSuperior, lista->nivel + 1);
	
	/*
	 Laço para percorrer todos os Snapshots que estão na ListaSnap apontada pelo 
	 parâmetro.
	*/
	while(lista->posAtual->prox != NULL)
	{
		// Snapshot que será analisado
		Snapshot* copia = (Snapshot*)calloc(1, sizeof(Snapshot));
		copiaSnapshot(copia, retornaSnapshotListaSnap(lista));
		FilaPos* fila = retornaFilaPosSnapshot(copia);
		
		while(fila->posAtual->prox != NULL)
		{
			/*
			 Tenta realizar as 4 possíveis movimentações com os pinos adjacentes ao 
			 pino apontado pelo primeiro da Fila de Posições Vazias do Snapshot copiado.
			*/
			Movimento* tentativa = (Movimento*)calloc(1, sizeof(Movimento));
			inicializaMovimento(tentativa, retornaFilaPosSnapshot(copia)->posAtual->prox->pos, CIMA);
			
			// Movimentação para CIMA
			if(possivelMovimentar(retornaTabuleiroSnapshot(copia), tentativa))
			{
				Snapshot* novo = (Snapshot*)calloc(1, sizeof(Snapshot));
				copiaSnapshot(novo, copia);
				acrescentaMovimentoSnapshot(novo, tentativa);
				FilaPos* filaPosVazia = retornaFilaPosSnapshot(novo);
				filaPosVazia->posAtual = filaPosVazia->head;
				acrescentaSnapshotListaSnap(listaSuperior, novo);
				liberaEspacoSnapshot(novo);
			}
			
			// Movimentação para BAIXO
			tentativa->movimento = BAIXO;
			if(possivelMovimentar(retornaTabuleiroSnapshot(copia), tentativa))
			{
				Snapshot* novo = (Snapshot*)calloc(1, sizeof(Snapshot));
				copiaSnapshot(novo, copia);
				acrescentaMovimentoSnapshot(novo, tentativa);
				FilaPos* filaPosVazia = retornaFilaPosSnapshot(novo);
				filaPosVazia->posAtual = filaPosVazia->head;
				acrescentaSnapshotListaSnap(listaSuperior, novo);
				liberaEspacoSnapshot(novo);
			}
			
			// Movimentação para DIREITA
			tentativa->movimento = DIREITA;
			if(possivelMovimentar(retornaTabuleiroSnapshot(copia), tentativa))
			{
				Snapshot* novo = (Snapshot*)calloc(1, sizeof(Snapshot));
				copiaSnapshot(novo, copia);
				acrescentaMovimentoSnapshot(novo, tentativa);
				FilaPos* filaPosVazia = retornaFilaPosSnapshot(novo);
				filaPosVazia->posAtual = filaPosVazia->head;
				acrescentaSnapshotListaSnap(listaSuperior, novo);
				liberaEspacoSnapshot(novo);
			}
			
			// Movimentação para ESQUERDA
			tentativa->movimento = ESQUERDA;
			if(possivelMovimentar(retornaTabuleiroSnapshot(copia), tentativa))
			{
				Snapshot* novo = (Snapshot*)calloc(1, sizeof(Snapshot));
				copiaSnapshot(novo, copia);
				acrescentaMovimentoSnapshot(novo, tentativa);
				FilaPos* filaPosVazia = retornaFilaPosSnapshot(novo);
				filaPosVazia->posAtual = filaPosVazia->head;
				acrescentaSnapshotListaSnap(listaSuperior, novo);
				liberaEspacoSnapshot(novo);
			}
			
			fila->posAtual = fila->posAtual->prox;
			liberaEspacoMovimento(tentativa);
		}
		
		liberaEspacoSnapshot(copia);
	}
	
	return listaSuperior;
}

/*
 Retorna uma referência para o Snapshot apontado pela posição atual da ListaSnap apontada pelo 
 parâmetro.
*/
Snapshot* retornaSnapshotListaSnap(ListaSnap* lista)
{
	lista->posAtual = lista->posAtual->prox;
	return lista->posAtual->snapshot;
}

/*
 Faz o ponteiro posAtual apontar para o início da ListaSnap apontada pelo parâmetro.
*/
void apontaPrimeiroListaSnap(ListaSnap* lista)
{
	lista->posAtual = lista->head;
}

/*
 Retorna 0 se a ListaSnap, apontada pelo parâmetro, não está vazia, ou um outro 
 número caso contrário.
*/
short listaSnapVazia(ListaSnap* lista)
{
	return (lista->head->prox == NULL);
}

/*
 Libera espaço da ListaSnap apontada pelo parâmetro.
*/
void liberaEspacoListaSnap(ListaSnap* lista)
{
	lista->posAtual = lista->head;
	
	// Libera toda a Lista de SnapListados
	SnapListado* retirado = lista->head->prox;	
	while(lista->head->prox != NULL)
	{
		lista->head->prox = retirado->prox;
		liberaEspacoSnapListado(retirado);
		retirado = lista->head->prox;
	}
	
	free(lista->head);
	
	free(lista);
}

/*
 Operação que verifica se é possível realizar o Movimento, apontado pelo segundo
 parâmetro no Tabuleiro apontado pelo primeiro parâmetro. Retorna 0 se não é 
 possível, ou outro número caso contrário.
*/
short possivelMovimentar(Tabuleiro* tabuleiro, Movimento* movimento)
{
	// Verifica se é possível o Movimento dependendo do tipo de movimentação
	switch(movimento->movimento)
	{
		case CIMA:
			// Verifica o estado dos pinos adjacentes
			if((retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) <
				 retornaQuantidadeLinhasTabuleiro(tabuleiro))
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		case BAIXO:
			// Verifica o estado dos pinos adjacentes
			if((retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) >= 0)
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		case DIREITA:
			// Verifica o estado dos pinos adjacentes
			if((retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) >= 0)
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		default:
			// Verifica o estado dos pinos adjacentes
			if((retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) <
				 retornaQuantidadeColunasTabuleiro(tabuleiro))
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1) == OCUPADA))
				{
					return 1;
				}
			}
			break;
	}
	
	// Não é possível realizar o Movimento apontado pelo parâmetro
	return 0;
}

