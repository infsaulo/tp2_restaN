/*
 Descrição:
 Tabuleiro.c implementa as operações do TAD Tabuleiro.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 01/05/2009
*/

// Bilbiotecas e referências necessárias
#include <stdlib.h>
#include "Tabuleiro.h"
#include "../IO/io.h"
/*
	Inicializa o Tabuleiro apontado pelo primeiro parâmetro com o snapshot inicial
	que está no arquivo, cujo nome é apontado pelo segundo parâmetro.
*/
void inicializaTabuleiro(Tabuleiro* tabuleiro, char* nomeArquivo)
{
	inicializaDadosTabuleiro(tabuleiro, nomeArquivo);
}

/*
 Retorna o estado da posição do Tabuleiro que é apontado pelo primeiro parâmetro.
 A linha e coluna desejada é passada pelo segundo e terceiro parâmetro.
*/
char retornaEstadoPosicaoTabuleiro(Tabuleiro* tabuleiro, short linha, short coluna)
{
	return tabuleiro->tabuleiro[linha][coluna];
}

/*
 Retorna a quantidade de posições vazias do Tabuleiro apontado pelo primeiro 
 parâmetro.
*/
short retornaQuantidadePosicoesVaziasTabuleiro(Tabuleiro* tabuleiro)
{
	return tabuleiro->quantidadePosicoesVazias;
}

/*
 Retorna a quantidade de posições ocupadas do Tabuleiro apontado pelo primeiro 
 parâmetro.
*/
short retornaQuantidadePosicoesOcupadasTabuleiro(Tabuleiro* tabuleiro)
{
	return tabuleiro->quantidadePosicoesOcupadas;
}

/*
 Retorna a quantidade de linhas do Tabuleiro apontado pelo parâmetro. 
*/
short retornaQuantidadeLinhasTabuleiro(Tabuleiro* tabuleiro)
{
	return tabuleiro->quantidadeLinhas;
}

/*
 Retorna a quantidade de colunas do Tabuleiro apontado pelo parâmetro.
*/
short retornaQuantidadeColunasTabuleiro(Tabuleiro* tabuleiro)
{
	return tabuleiro->quantidadeColunas;
}

/*
 Modifica o estado da posição do Tabuleiro apontado pelo primeiro parâmetro. A
 linha e coluna desejadas são passados pelo segundo e terceiro parâmetro. O quarto
 parâmetro é o novo estado.
*/
void modificaEstadoPosicaoTabuleiro(Tabuleiro* tabuleiro, short linha, short coluna, char novoEstado)
{
	if(tabuleiro->tabuleiro[linha][coluna] == OCUPADA)
	{
		(tabuleiro->quantidadePosicoesOcupadas)--;
	}
	
	else
	{
		if(tabuleiro->tabuleiro[linha][coluna] == VAZIA)
		{
			(tabuleiro->quantidadePosicoesVazias)--;
		}
	}
	
	tabuleiro->tabuleiro[linha][coluna] = novoEstado;
	
	if(tabuleiro->tabuleiro[linha][coluna] == OCUPADA)
	{
		(tabuleiro->quantidadePosicoesOcupadas)++;
	}
	
	else
	{
		if(tabuleiro->tabuleiro[linha][coluna] == VAZIA)
		{
			(tabuleiro->quantidadePosicoesVazias)++;
		}
	}
}

/*
 Libera espaço alocado para o Tabuleiro apontado pelo parâmetro.
*/
void liberaEspacoTabuleiro(Tabuleiro* tabuleiro)
{
	int iteratorLinha;
	for(iteratorLinha = 0; iteratorLinha < tabuleiro->quantidadeLinhas; iteratorLinha++)
	{
		free(tabuleiro->tabuleiro[iteratorLinha]);
	}
	
	free(tabuleiro->tabuleiro);
	free(tabuleiro);
}

