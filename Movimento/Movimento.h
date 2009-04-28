#ifndef MOVIMENTO
#define MOVIMENTO

/*
 Descrição:
 Movimento.h define o TAD Movimento e a sua estrutura de dados.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 27/04/2009
*/

// Biblioteca necessária
#include "../Posicao/Posicao.h"

// Estrutura de dados que define um Movimento
typedef struct Movimento
{
	// Posição no tabuleiro do pino que é movimentado
	Posicao* posicao;
	
	// Movimento realizado pelo pino que estava na posição referenciada
	short movimento;
}Movimento;

/*
 Mapeamentos de cada movimentação possível sobre o tabuleiro do resta n.
*/
#define CIMA 1
#define ESQUERDA 2
#define BAIXO 3
#define DIREITA 4

/*
 Operações sobre o TAD Movimento, com o pino cuja posição é apontada pelo 
 primeiro parâmetro e o movimento realizado por tal pino é passado pelo segundo
 parâmetro.
*/

void inicializaMovimento(Movimento* movimento, Posicao* posicao, short movimentacao);

/*
 Retorna a posição do pino que foi movimentado do Movimento apontado pelo 
 parâmetro.
*/
Posicao* retornaPosicaoPinoMovimento(Movimento* movimento);

/*
 Retorna o movimento realizado pelo pino do Movimento apontado pelo parâmetro.
*/
short retornaMovimentacaoMovimento(Movimento* movimento);

/*
 Copia o conteúdo do movimento apontado pelo segundo parâmetro para o movimento
 apontado pelo primeiro parâmetro.
*/
void copiaMovimento(Movimento* movimento1, Movimento* movimento2);

// Libera espaço de memória alocado pelo Movimento apontado pelo parâmetro.
void liberaEspacoMovimento(Movimento* movimento);

#endif

