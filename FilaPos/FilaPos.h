#ifndef FILAPOS
#define FILAPOS
/*
 Decrição:
 FilaPos.h define o TAD que representa uma fila de Posições, assim como a 
 interface das estruturas de dados necessárias.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 28/04/2009
*/

// Referência para o módulo Posicao
#include "../Posicao/Posicao.h"

/*
 Estrutura de dados que representa uma entidade que está inserida na Fila de 
 Posições.
*/
typedef struct Cel
{
	// Posição
	Posicao* pos;
	
	// Apontador para a próxima Cel da Fila
	struct Cel* prox;
}Cel;

/*
 Estrutura de dados que define a interface do TAD Fila de Posições
*/
typedef struct FilaPos
{
	// Cel Head para a Fila de Posições
	Cel* head;
	
	/*
	 Apontador para a Cel, cuja posição está sendo utilizada num determinado
	 momento.
	*/
	Cel* posAtual;
	
	// Apontador para a última Cel da FilaPos
	Cel* ultima;
	
}FilaPos;

// Operações sobre o TAD Cel
/*
 Inicializa a Cel, apontada pelo primeiro parâmetro, com a Posição apontada pelo
 segundo parâmetro. E, também, atribui NULL para o apontador para a próxima Cel.
*/
void inicializaCel(Cel* cel, Posicao* posicao);

/*
 Libera o espaco alocado para a Cel apontada pelo parâmetro.
*/
void liberaEspacoCel(Cel* cel);

// Operações sobre o TAD FilaPos

// Inicializa a Fila apontada pelo parâmetro como vazia
void inicializaFilaPos(FilaPos* fila);

/* 
 Enfileira a Posicao apontada pelo segundo parâmetro na FilaPos apontada pelo
 primeiro parâmetro.
*/
void enfileiraFilaPos(FilaPos* fila, Posicao* pos);

/*
 Desenfileira a Cel que está sendo apontada pelo campo posAtual da FilaPos 
 apontada pelo parâmetro.
*/
void desenfileiraFilaPos(FilaPos* fila);

/*
 Verifica se a FilaPos, apontada pelo parâmetro, está vazia. Retorna 0 se a FilaPos
 não está vazia, ou um outro número caso contrário.
*/
short filaPosVazia(FilaPos* fila);

/*
 Copia a FilaPos apontada pelo segundo parâmetro para a filaPos apontada pelo primeiro
 parâmetro.
*/
void copiaFilaPos(FilaPos* fila1, FilaPos* fila2);

/*
 Libera espaço da memória alocada para a FilaPos apontada pelo parâmetro.
*/
void liberaEspacoFilaPos(FilaPos* fila);

#endif

