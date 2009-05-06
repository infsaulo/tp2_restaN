/*
 Descrição:
 PilhaMov.c implementa as funções que agem sobre o TAD Pilha de Movimentos.

 Autor:
 Saulo Marques Ribeiro Ricci

 Data:
 29/04/2009
*/

// Bibliotecas necessárias
#include <stdlib.h>
#include "PilhaMov.h"

// Operações sobre o TAD Elemento
/*
 Inicializa o Elemento, apontada pelo primeiro parâmetro, com o Movimento apontado
 pelo segundo parâmetro. E, também, atribui NULL para o apontador para a próximo
 Elemento.
*/
void inicializaElemento(Elemento* elemento, Movimento* movimento)
{
	elemento->mov = (Movimento*)calloc(1, sizeof(Movimento));
	copiaMovimento(elemento->mov, movimento);
	
	elemento->prox = NULL;
}

/*
 Libera o espaco alocado para o Elemento apontado pelo parâmetro.
*/
void liberaEspacoElemento(Elemento* elemento)
{
	liberaEspacoMovimento(elemento->mov);
	free(elemento);
}

// Operações sobre o TAD Pilha de Movimentos

/*
 Inicializa o Pilha de Movimentos apontada pelo parâmetro como vazia.
*/
void inicializaPilhaMov(PilhaMov* pilha)
{
	pilha->fundo = (Elemento*)calloc(1, sizeof(Elemento));
	pilha->fundo->prox = NULL;
	
	pilha->topo = pilha->fundo;
	
	pilha->quantidadeElementos = 0;
}

/*
 Empilha o Movimento apontado pelo segundo parâmetro na PilhaMov apontada pelo
 primeiro parâmetro.
*/
void empilhaPilhaMov(PilhaMov* pilha, Movimento* movimento)
{
	// Elemento que será empilhado na PilhaMov apontada pelo primeiro parâmetro
	Elemento* novo = (Elemento*)calloc(1, sizeof(Elemento));
	inicializaElemento(novo, movimento);
	
	novo->prox = pilha->topo;
	pilha->topo = novo;
	(pilha->quantidadeElementos)++;
	
}

/*
 Desempilha o Movimento que está no topo da PilhaMov apontada pelo parâmetro.
*/
Movimento* desempilhaPilhaMov(PilhaMov* pilha)
{
   if(!pilhaMovVazia(pilha))
   {
	   // Apontador para o Elemento que será retirado
	   Elemento* retirado = pilha->topo;
	   
	   pilha->topo = retirado->prox;
	   
	   (pilha->quantidadeElementos)--;
	   
   	Movimento* movimentoRetirado = (Movimento*)calloc(1, sizeof(Movimento));
		copiaMovimento(movimentoRetirado, retirado->mov);
		liberaEspacoElemento(retirado);
	
		return movimentoRetirado;
	}
	
	return NULL;
	
}

/*
 Verifica se a PilhaMov, apontada pelo parâmetro, está vazia. Retorna 0 se a PilhaMov
 não está vazia, ou um outro número caso contrário.
*/
short pilhaMovVazia(PilhaMov* pilha)
{
   return (pilha->topo == pilha->fundo);
}

/*
 Copia a PilhaMov apontada pelo segundo parâmetro para a PilhaMov apontada pelo
 primeiro parâmetro.
*/
void copiaPilhaMov(PilhaMov* pilha1, PilhaMov* pilha2)
{
	// Lista que copia os Elementos empilhados na ordem adequada
	Elemento* lista = (Elemento*)calloc(1, sizeof(Elemento));
	lista->prox = NULL;
	
	Elemento *apt1, *apt2;
	for(apt1 = pilha2->topo, apt2 = lista; apt1 != pilha2->fundo; apt1 = apt1->prox, apt2 = apt2->prox)
	{
		Elemento* novo = (Elemento*)calloc(1, sizeof(Elemento));
		inicializaElemento(novo, apt1->mov);
		apt2->prox = novo;
	}
	
	// Finaliza o processo de cópia
	apt2->prox = pilha1->fundo;
	
	apt2 = lista;
	pilha1->topo = apt2->prox;
	
	free(lista);
	
	pilha1->quantidadeElementos = pilha2->quantidadeElementos;
}

/*
 Libera espaço da memória alocada para a PilhaMov apontada pelo parâmetro.
*/
void liberaEspacoPilhaMov(PilhaMov* pilha)
{
   while(!pilhaMovVazia(pilha))
   {
      desempilhaPilhaMov(pilha);
   }
   
   /*
    Libera espaço de memória alocada para o fundo da PilhaMov apontada pelo 
    parâmetro.
   */
   free(pilha->fundo);
   free(pilha);
}

