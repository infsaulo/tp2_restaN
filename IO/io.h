#ifndef IO
#define IO

/*
 Descrição:
 io.h define os protótipos das funções para operações de entrada/saída de dados
 do jogo, assim como operações básicas para manipulação dos dados.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 01/05/2009
*/

// Referências necessárias
#include "../Resta_N/Tabuleiro/Tabuleiro.h"
#include "../Resta_N/PilhaMov/PilhaMov.h"

/*
 Inicializa o Tabuleiro apontado pelo primeiro parâmetro com o snapshot inicial,
 que está no arquivo, cujo nome é apontado pela segunda posição.
*/
void inicializaDadosTabuleiro(Tabuleiro* tabuleiro, char* nomeArquivo);

/*
 Escreve todos os movimentos que foram realizados no Jogo. A pilha de movimentos 
 do Jogo, que contém tais movimentos é apontada pelo primeiro parâmetro. O nome
 do arquivo que conterá os movimentos é apontado pelo terceiro parâmetro e o 
 Tabuleiro é apontado pelo segundo parâmetro.
*/
void escreveMovimentosJogadas(PilhaMov* pilhaMovimentos, Tabuleiro* tabuleiro, char* nomeArquivo);

/*
 Copia a matriz apontada pelo segundo parâmetro para a matriz apontada pelo 
 primeiro parâmetro. As dimensões são passadas pelo terceiro e quarto parâmetros.
*/
void copiaDadosMatriz(char** mat1, char** mat2, short quantidadeLinhas, short quantidadeColunas);

#endif

