/*
 Descrição:
 principal.c implementa a função principal do Jogo Resta_N.
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 08/05/2009
*/

// Bibliotecas e referências necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../Resta_N/Jogo/Jogo.h"

// Definição de constantes
#define NENHUM_ARG -1

// Função principal
int main(int argc, char** argv)
{
	
	/*
	 Captura os dados que são passados pela linha de comando
	*/
	
	/*
	 nomeArquivo é um array de strings que contém os nomes do arquivo de entrada 
	 e de saida.
	*/

	char* nomeArquivo[2];
	
	// k é o nível das jogadas desejada pelo usuário
	int k;
	
	int opcao;
	opcao = getopt(argc, argv, "e:s:k:");
	
	while(opcao != NENHUM_ARG)
	{
		switch(opcao)
		{
			case 'e':
				nomeArquivo[0] = (char*)calloc(strlen(optarg)+1, sizeof(char));
				strcpy(nomeArquivo[0], optarg);
				break;
			case 's':
				nomeArquivo[1] = (char*)calloc(strlen(optarg)+1, sizeof(char));
				strcpy(nomeArquivo[1], optarg);
				break;
			case 'k':
				k = atoi(optarg);
				break;
		}
		
		opcao = getopt(argc, argv, "e:s:k:");
	}
	
	// Realiza as jogadas sobre o Tabuleiro especificado no arquivo de entrada.
	Jogo* jogo = (Jogo*)calloc(1, sizeof(Jogo));
	inicializaJogo(jogo, nomeArquivo[0], k);
	
	jogar(jogo);
	
	escrevePassosJogo(jogo, nomeArquivo[1]);
		
	liberaEspacoJogo(jogo);
	free(nomeArquivo[0]);
	free(nomeArquivo[1]);
	
	return 0;
}
