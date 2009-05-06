#ifndef POSICAO
#define POSICAO

/*
 Descrição:
 Posicao.h define o TAD Posicação que representa cada posição no tabuleiro do
 jogo Resta n.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 27/04/2009
*/

// Estrutura de dados Posicao.
typedef struct Posicao
{
	short linha;
	short coluna;
}Posicao;

// Funções que agem sobre o TAD Posição

/*
 Inicializa a Posicao apontada pelo parâmetro com a linha e coluna passados pelos
 outros parâmetros.
*/
void inicializaPosicao(Posicao* posicao, short linha, short coluna);

/*
 Retorna a linha da Posição apontada pelo parâmetro.
*/
short retornaLinhaPosicao(Posicao* posicao);

/*
 Retorna a coluna da Posição apontada pelo parâmetro.
*/
short retornaColunaPosicao(Posicao* posicao);

/*
 Copia o conteúdo da posição apontada pelo segundo parâmetro para a posição
 apontada pelo primeiro parâmetro.
*/
void copiaPosicao(Posicao* posicao1, Posicao* posicao2);


/*
 Libera espaco de memória alocada para a Posição apontada pelo parâmetro.
*/
void liberaEspacoPosicao(Posicao* posicao);

#endif

