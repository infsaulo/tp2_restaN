#ifndef PILHAMOV
#define PILHAMOV

/*
 Descrição:
 PilhaMov.h define a  interface e também as estruturas de dados utilizadas para
 implementar o TAD Pilha de Movimentos.

 Autor:
 Saulo Marques Ribeiro Ricci

 Data:
 29/04/2009
*/

// Bibliotecas necessárias
#include "../Movimento/Movimento.h"

/*
 Estrutura de dados que define um elemento empilhado
*/
typedef struct Elemento
{
	// Movimento empilhado
	Movimento* mov;

	// Apontado para o próximo Elemento
	struct Elemento* prox;

}Elemento;

/*
 Estrutura de dados que define a interface do TAD Pilha de Movimentos
*/
typedef struct PilhaMov
{
	// Fundo da Pilha de Movimentos
	Elemento* fundo;

	// Apontador para o Elemento que está no topo da Pilha de Movimentos
	Elemento* topo;

	// Quantidade de Elementos que está na Pilha de Movimentos
	short quantidadeElementos;
}PilhaMov;

// Operações sobre o TAD Elemento
/*
 Inicializa o Elemento, apontada pelo primeiro parâmetro, com o Movimento apontado
 pelo segundo parâmetro. E, também, atribui NULL para o apontador para a próximo
 Elemento.
*/
void inicializaElemento(Elemento* elemento, Movimento* movimento);

/*
 Libera o espaco alocado para o Elemento apontado pelo parâmetro.
*/
void liberaEspacoElemento(Elemento* elemento);

// Operações sobre o TAD Pilha de Movimentos

/*
 Inicializa o Pilha de Movimentos apontada pelo parâmetro como vazia.
*/
void inicializaPilhaMov(PilhaMov* pilha);

/*
 Empilha o Movimento apontado pelo segundo parâmetro na PilhaMov apontada pelo
 primeiro parâmetro.
*/
void empilhaPilhaMov(PilhaMov* pilha, Movimento* movimento);

/*
 Desempilha o Movimento que está no topo da PilhaMov apontada pelo parâmetro.
*/
void desempilhaPilhaMov(PilhaMov* pilha);

/*
 Verifica se a PilhaMov, apontada pelo parâmetro, está vazia. Retorna 0 se a PilhaMov
 não está vazia, ou um outro número caso contrário.
*/
short pilhaMovVazia(PilhaMov* pilha);

/*
 Libera espaço da memória alocada para a PilhaMov apontada pelo parâmetro.
*/
void liberaEspacoPilhaMov(PilhaMov* pilha);

#endif

