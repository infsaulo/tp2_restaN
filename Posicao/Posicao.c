/*
 Descrição:
 Posicao.c implementa as funções que agem sobre o TAD Posicao.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 27/04/2009
*/

// Bibliotecas necessárias
#include <stdlib.h>
#include "Posicao.h"

/*
 Inicializa a Posicao apontada pelo parâmetro com a linha e coluna passados pelos
 outros parâmetros.
*/
void inicializaPosicao(Posicao* posicao, short linha, short coluna)
{
	posicao->linha = linha;
	posicao->coluna = coluna;
}

/*
 Retorna a linha da Posição apontada pelo parâmetro.
*/
short retornaLinhaPosicao(Posicao* posicao)
{
	return posicao->linha;
}

/*
 Retorna a coluna da Posição apontada pelo parâmetro.
*/
short retornaColunaPosicao(Posicao* posicao)
{
	return posicao->coluna;
}

/*
 Copia o conteúdo da posição apontada pelo segundo parâmetro para a posição
 apontada pelo primeiro parâmetro.
*/
void copiaPosicao(Posicao* posicao1, Posicao* posicao2)
{
	posicao1->linha = posicao2->linha;
	posicao1->coluna = posicao2->coluna;
}


/*
 Libera espaco de memória alocada para a Posição apontada pelo parâmetro.
*/
void liberaEspacoPosicao(Posicao* posicao)
{
	free(posicao);
}

