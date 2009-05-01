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
#include "../Tabuleiro/Tabuleiro.h"

/*
 Inicializa o Tabuleiro apontado pelo primeiro parâmetro com o snapshot inicial,
 que está no arquivo, cujo nome é apontado pela segunda posição.
*/
void inicializaDadosTabuleiro(Tabuleiro* tabuleiro, char* nomeArquivo);

/*
 Copia a matriz apontada pelo segundo parâmetro para a matriz apontada pelo 
 primeiro parâmetro. As dimensões são passadas pelo terceiro e quarto parâmetros.
*/
void copiaDadosMatriz(char** mat1, char** mat2, short quantidadeLinhas, short quantidadeColunas);

#endif

