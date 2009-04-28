/*
 Descrição:
 Movimento.c implementa o TAD Movimento
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 27/04/2009
*/

// Bibliotecas necessárias
#include <stdlib.h>
#include "Movimento.h"

/*
 Operações sobre o TAD Movimento, com o pino cuja posição é apontada pelo 
 primeiro parâmetro e o movimento realizado por tal pino é passado pelo segundo
 parâmetro.
*/

void inicializaMovimento(Movimento* movimento, Posicao* posicao, short movimentacao)
{
	movimento->posicao = (Posicao*)calloc(1, sizeof(Posicao));
	copiaPosicao(movimento->posicao, posicao);
	movimento->movimento = movimentacao;
}

/*
 Retorna a posição do pino que foi movimentado do Movimento apontado pelo 
 parâmetro.
*/
Posicao* retornaPosicaoPinoMovimento(Movimento* movimento)
{
	return movimento->posicao;
}

/*
 Retorna o movimento realizado pelo pino do Movimento apontado pelo parâmetro.
*/
short retornaMovimentacaoMovimento(Movimento* movimento)
{
	return movimento->movimento;
}

/*
 Copia o conteúdo do movimento apontado pelo segundo parâmetro para o movimento
 apontado pelo primeiro parâmetro.
*/
void copiaMovimento(Movimento* movimento1, Movimento* movimento2)
{
	liberaEspacoPosicao(movimento1->posicao);
	movimento1->posicao = (Posicao*)calloc(1, sizeof(Posicao));
	copiaPosicao(movimento1->posicao, movimento2->posicao);
	movimento1->movimento = movimento2->movimento;
}

// Libera espaço de memória alocado pelo Movimento apontado pelo parâmetro.
void liberaEspacoMovimento(Movimento* movimento)
{
	liberaEspacoPosicao(movimento->posicao);
	free(movimento);
}

