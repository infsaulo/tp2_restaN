/*
 Descrição:
 io.c implementa as funções cujos protótipos estão definidos no arquivo io.h.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 01/05/2009
*/

// Bibliotecas e referências necessárias
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

/*
 Inicializa o Tabuleiro apontado pelo primeiro parâmetro com o snapshot inicial,
 que está no arquivo, cujo nome é apontado pela segunda posição.
*/
void inicializaDadosTabuleiro(Tabuleiro* tabuleiro, char* nomeArquivo)
{
	
	// Arquivo que contém o snapshot inicial do Tabuleiro do jogo
	FILE* arq = fopen(nomeArquivo, "r");
	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo do snapshot do jogo!\n");
		exit(-1);
	}
	
	// Recolhe os dados
	tabuleiro->quantidadePosicoesVazias = 0;
	tabuleiro->quantidadePosicoesOcupadas = 0;
	
	fscanf(arq, "%d %d\n", &(tabuleiro->quantidadeLinhas), &(tabuleiro->quantidadeColunas));
	
	int iteratorLinha, iteratorColuna;
	tabuleiro->tabuleiro = (char**)calloc(tabuleiro->quantidadeLinhas, sizeof(char*));
	for(iteratorLinha = 0; iteratorLinha < tabuleiro->quantidadeLinhas; iteratorLinha++)
	{
		tabuleiro->tabuleiro[iteratorLinha] = (char*)calloc(tabuleiro->quantidadeColunas, sizeof(char));
	}
	
	for(iteratorLinha = 0; iteratorLinha < tabuleiro->quantidadeLinhas; iteratorLinha++)
	{
		for(iteratorColuna = 0; iteratorColuna < tabuleiro->quantidadeColunas; iteratorColuna++)
		{
			fscanf(arq, "%c ", &(tabuleiro->tabuleiro[iteratorLinha][iteratorColuna]));
			
			// Atualiza a quantidade das posições vazias, ou ocupadas
			if(tabuleiro->tabuleiro[iteratorLinha][iteratorColuna] == OCUPADA)
			{
				(tabuleiro->quantidadePosicoesOcupadas)++;
			}
			
			else
			{
				if(tabuleiro->tabuleiro[iteratorLinha][iteratorColuna] == VAZIA)
				{
					(tabuleiro->quantidadePosicoesVazias)++;
				}
			}
		}
	}
	
	fclose(arq);
}

/*
 Escreve todos os movimentos que foram realizados no Jogo. A pilha de movimentos 
 do Jogo, que contém tais movimentos é apontada pelo primeiro parâmetro. O nome
 do arquivo que conterá os movimentos é apontado pelo terceiro parâmetro e o 
 Tabuleiro é apontado pelo segundo parâmetro.
*/
void escreveMovimentosJogadas(PilhaMov* pilhaMovimentos, Tabuleiro* tabuleiro, char* nomeArquivo)
{
	// Arquivo que conterá os dados do Movimentos
	FILE* arq = fopen(nomeArquivo, "w");
	
	// Vetor de Movimentos
	Movimento* movimentos[pilhaMovimentos->quantidadeElementos];
	
	if(arq == NULL)
	{
		printf("Erro ao tentar abrir o arquivo de dados de Movimentos!!!\n");
		exit(-1);
	}
	
	int pos = pilhaMovimentos->quantidadeElementos - 1;
	int tamanho = pilhaMovimentos->quantidadeElementos;
	while(!pilhaMovVazia(pilhaMovimentos))
	{
		movimentos[pos] = desempilhaPilhaMov(pilhaMovimentos);
		pos--;
	}
	
	// Escreve a quantidadade de pinos restantes
	fprintf(arq, "%d\n", retornaQuantidadePosicoesOcupadasTabuleiro(tabuleiro));
	
	// Escreve os Movimentos
	for(pos = 0; pos < tamanho; pos++)
	{
		fprintf(arq, "<%d, %d>: ", movimentos[pos]->posicao->linha, movimentos[pos]->posicao->coluna);
		
		switch(movimentos[pos]->movimento)
		{
			case CIMA:
				fprintf(arq, "cima\n");
				break;
			
			case BAIXO:
				fprintf(arq, "baixo\n");
				break;
			
			case DIREITA:
				fprintf(arq, "direita\n");
				break;
			
			default:
				fprintf(arq, "esquerda\n");
				break;	
		}
		
		liberaEspacoMovimento(movimentos[pos]);
	}
	
	fclose(arq);
}

/*
 Copia a matriz apontada pelo segundo parâmetro para a matriz apontada pelo 
 primeiro parâmetro. As dimensões são passadas pelo terceiro e quarto parâmetros.
*/
void copiaDadosMatriz(char** mat1, char** mat2, short quantidadeLinhas, short quantidadeColunas)
{
	int iteratorLinha,iteratorColuna;
	
	for(iteratorLinha = 0; iteratorLinha < quantidadeLinhas; iteratorLinha++)
	{
		for(iteratorColuna = 0; iteratorColuna < quantidadeColunas; iteratorColuna++)
		{
			mat1[iteratorLinha][iteratorColuna] = mat2[iteratorLinha][iteratorColuna];
		}
	}
}

