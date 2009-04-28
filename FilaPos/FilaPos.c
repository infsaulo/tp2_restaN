/*
 Descrição:
 FilaPos.c implementa as operações que agem sobre a estrutura de dados, cuja
 função é representar o TAD FilaPos.
 
 Autor: 
 Saulo Marques Ribeiro Ricci
 
 Data:
 28/04/2009
*/

// Biliotecas necessárias
#include <stdlib.h>
#include "FilaPos.h"

// Operações sobre o TAD Cel
/*
 Inicializa a Cel, apontada pelo primeiro parâmetro, com a Posição apontada pelo
 segundo parâmetro. E, também, atribui NULL para o apontador para a próxima Cel.
*/
void inicializaCel(Cel* cel, Posicao* posicao)
{
	cel->pos = (Posicao*)calloc(1, sizeof(Posicao));
	copiaPosicao(cel->pos, posicao);
	
	cel->prox = NULL;
}

/*
 Libera o espaco alocado para a Cel apontada pelo parâmetro.
*/
void liberaEspacoCel(Cel* cel)
{
	liberaEspacoPosicao(cel->pos);
	free(cel);
}

// Inicializa a Fila apontada pelo parâmetro como vazia
void inicializaFilaPos(FilaPos* fila)
{
	fila->head = (Cel*)calloc(1, sizeof(Cel));
	fila->head->prox = NULL;
	
	fila->posAtual = fila->head;
	fila->ultima = fila->head;
}

/* 
 Enfileira a Posicao apontada pelo segundo parâmetro na FilaPos apontada pelo
 primeiro parâmetro.
*/
void enfileiraFilaPos(FilaPos* fila, Posicao* pos)
{
	// Cel que será enfileirada
	Cel* nova = (Cel*)calloc(1, sizeof(Cel));
	inicializaCel(nova, pos);
	
	fila->ultima->prox = nova;
	fila->ultima = nova;
}

/*
 Desenfileira a Cel que está sendo apontada pelo campo posAtual da FilaPos 
 apontada pelo parâmetro.
*/
void desenfileiraFilaPos(FilaPos* fila)
{
	// Desenfileira a Cel apontada pelo campo posAtual
	if(!filaPosVazia(fila))
	{
		Cel* retirada = fila->posAtual->prox;
		fila->posAtual->prox = fila->posAtual->prox->prox;
		
		liberaEspacoCel(retirada);
	}
}

/*
 Verifica se a FilaPos, apontada pelo parâmetro, está vazia. Retorna 0 se a FilaPos
 não está vazia, ou um outro número caso contrário.
*/
short filaPosVazia(FilaPos* fila)
{
	return (fila->head->prox == NULL);
}

/*
 Libera espaço da memória alocada para a FilaPos apontada pelo parâmetro.
*/
void liberaEspacoFilaPos(FilaPos* fila)
{
	fila->posAtual = fila->head;
	while(!filaPosVazia(fila))
	{
		desenfileiraFilaPos(fila);
	}
	
	free(fila->head);
	free(fila);
}

