#ifndef TABULEIRO
#define TABULEIRO

/*
 Descrição:
 Tabuleiro.h define a interface do TAD Tabuleiro do jogo resta n.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 01/05/2009
*/
// Definição de constantes
#define VAZIA '0'
#define OCUPADA '1'
#define IMPOSSIVEL 'x'

// Referências necessárias
#include "../FilaPos/FilaPos.h"
#include "../Movimento/Movimento.h"

// Estrutura de dados Tabuleiro
typedef struct Tabuleiro
{
	// Apontador para matriz que é um snapshot do Tabuleiro do jogo
	char** tabuleiro;
	
	// Dimensões da matriz
	short quantidadeLinhas, quantidadeColunas;
	
	// Outros dados
	short quantidadePosicoesVazias, quantidadePosicoesOcupadas;
}Tabuleiro;

// Operações sobre o TAD Tabuleiro

/*
	Inicializa o Tabuleiro apontado pelo primeiro parâmetro com o snapshot inicial
	que está no arquivo, cujo nome é apontado pelo segundo parâmetro.
*/
void inicializaTabuleiro(Tabuleiro* tabuleiro, char* nomeArquivo);

/*
 Retorna o estado da posição do Tabuleiro que é apontado pelo primeiro parâmetro.
 A linha e coluna desejada é passada pelo segundo e terceiro parâmetro.
*/
char retornaEstadoPosicaoTabuleiro(Tabuleiro* tabuleiro, short linha, short coluna);

/*
 Retorna a quantidade de posições vazias do Tabuleiro apontado pelo primeiro 
 parâmetro.
*/
short retornaQuantidadePosicoesVaziasTabuleiro(Tabuleiro* tabuleiro);

/*
 Retorna a quantidade de posições ocupadas do Tabuleiro apontado pelo primeiro 
 parâmetro.
*/
short retornaQuantidadePosicoesOcupadasTabuleiro(Tabuleiro* tabuleiro);

/*
 Retorna a quantidade de linhas do Tabuleiro apontado pelo parâmetro. 
*/
short retornaQuantidadeLinhasTabuleiro(Tabuleiro* tabuleiro);

/*
 Retorna a quantidade de colunas do Tabuleiro apontado pelo parâmetro.
*/
short retornaQuantidadeColunasTabuleiro(Tabuleiro* tabuleiro);

/*
 Copia os dados do Tabuleiro apontado pelo segundo parâmetro para o Tabuleiro
 apontado pelo primeiro parâmetro.
*/
void copiaTabuleiro(Tabuleiro* tab1, Tabuleiro* tab2);

/*
 Modifica o estado da posição do Tabuleiro apontado pelo primeiro parâmetro. A
 linha e coluna desejadas são passados pelo segundo e terceiro parâmetro. O quarto
 parâmetro é o novo estado.
*/
void modificaEstadoPosicaoTabuleiro(Tabuleiro* tabuleiro, short linha, short coluna, char novoEstado);


/*
 Retorna uma referência de uma FilaPos que contém todas as posições vazias do 
 Tabuleiro apontado pelo parâmetro.
*/
FilaPos* retornaPosVaziasTabuleiro(Tabuleiro* tabuleiro);

/*
 Operação que verifica se é possível realizar o Movimento, apontado pelo segundo
 parâmetro no Tabuleiro apontado pelo primeiro parâmetro. Retorna 0 se não é 
 possível, ou outro número caso contrário.
*/
short possivelMovimentar(Tabuleiro* tabuleiro, Movimento* movimento);

/*
 Retorna a quantidade de movimentos que podem ser realizados pelo tabuleiro 
 apontado pelo parâmetro.
*/
short retornaQuantidadeMovimentacoesPossiveisTabuleiro(Tabuleiro* tabuleiro);

/*
 Libera espaço alocado para o Tabuleiro apontado pelo parâmetro.
*/
void liberaEspacoTabuleiro(Tabuleiro* tabuleiro);

#endif

