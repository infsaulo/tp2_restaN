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
 Modifica o estado da posição do Tabuleiro apontado pelo primeiro parâmetro. A
 linha e coluna desejadas são passados pelo segundo e terceiro parâmetro. O quarto
 parâmetro é o novo estado.
*/
void modificaEstadoPosicaoTabuleiro(Tabuleiro* tabuleiro, short linha, short coluna, char novoEstado);

/*
 Libera espaço alocado para o Tabuleiro apontado pelo parâmetro.
*/
void liberaEspacoTabuleiro(Tabuleiro* tabuleiro);

#endif

