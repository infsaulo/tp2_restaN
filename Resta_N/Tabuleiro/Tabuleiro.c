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
#include "../../IO/io.h"
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
 Copia os dados do Tabuleiro apontado pelo segundo parâmetro para o Tabuleiro
 apontado pelo primeiro parâmetro.
*/
void copiaTabuleiro(Tabuleiro* tab1, Tabuleiro* tab2)
{
	int iterator;
	tab1->tabuleiro = (char**)calloc(tab2->quantidadeLinhas, sizeof(char*));
	for(iterator = 0; iterator < tab2->quantidadeLinhas; iterator++)
	{
		tab1->tabuleiro[iterator] = (char*)calloc(tab2->quantidadeColunas, sizeof(char));
	}
	copiaDadosMatriz(tab1->tabuleiro, tab2->tabuleiro, tab2->quantidadeLinhas, tab2->quantidadeColunas);
	
	tab1->quantidadeLinhas = tab2->quantidadeLinhas;
	tab1->quantidadeColunas = tab2->quantidadeColunas;
	tab1->quantidadePosicoesVazias = tab2->quantidadePosicoesVazias;
	tab1->quantidadePosicoesOcupadas = tab2->quantidadePosicoesOcupadas;
}

/*
 Retorna uma referência de uma FilaPos que contém todas as posições vazias do 
 Tabuleiro apontado pelo parâmetro.
*/
FilaPos* retornaPosVaziasTabuleiro(Tabuleiro* tabuleiro)
{
	// FilaPos que contém as posições vazias do Tabuleiro apontado pelo parâmetro.
	FilaPos* posVazias = (FilaPos*)calloc(1, sizeof(FilaPos));
	inicializaFilaPos(posVazias);
	
	Posicao* pos = (Posicao*)calloc(1, sizeof(Posicao));
	inicializaPosicao(pos, 0, 0);
	
	int iteratorLinha, iteratorColuna;
	
	for(iteratorLinha = 0; iteratorLinha < retornaQuantidadeLinhasTabuleiro(tabuleiro); iteratorLinha++)
	{
		for(iteratorColuna = 0; iteratorColuna < retornaQuantidadeColunasTabuleiro(tabuleiro); iteratorColuna++)
		{
			if(retornaEstadoPosicaoTabuleiro(tabuleiro, iteratorLinha, iteratorColuna) == VAZIA)
			{
				pos->linha = iteratorLinha;
				pos->coluna = iteratorColuna;
				enfileiraFilaPos(posVazias, pos);
			}
		}
	}
	
	liberaEspacoPosicao(pos);
	
	return posVazias;
}

/*
 Operação que verifica se é possível realizar o Movimento, apontado pelo segundo
 parâmetro no Tabuleiro apontado pelo primeiro parâmetro. Retorna 0 se não é 
 possível, ou outro número caso contrário.
*/
short possivelMovimentar(Tabuleiro* tabuleiro, Movimento* movimento)
{
	// Verifica se é possível o Movimento dependendo do tipo de movimentação
	switch(movimento->movimento)
	{
		case CIMA:
			// Verifica o estado dos pinos adjacentes
			if((retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) <
				 retornaQuantidadeLinhasTabuleiro(tabuleiro))
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		case BAIXO:
			// Verifica o estado dos pinos adjacentes
			if((retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) >= 0)
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1,
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento))) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		case DIREITA:
			// Verifica o estado dos pinos adjacentes
			if((retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) >= 0)
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 2) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) - 1) == OCUPADA))
				{
					return 1;
				}
			}
			break;
		
		default:
			// Verifica o estado dos pinos adjacentes
			if((retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) <
				 retornaQuantidadeColunasTabuleiro(tabuleiro))
			{
				if((retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 2) == OCUPADA) && 
					(retornaEstadoPosicaoTabuleiro(tabuleiro, retornaLinhaPosicao(retornaPosicaoPinoMovimento(movimento)),
					retornaColunaPosicao(retornaPosicaoPinoMovimento(movimento)) + 1) == OCUPADA))
				{
					return 1;
				}
			}
			break;
	}
	
	// Não é possível realizar o Movimento apontado pelo parâmetro
	return 0;
}


/*
 Retorna a quantidade de movimentos que podem ser realizados pelo tabuleiro 
 apontado pelo parâmetro.
*/
short retornaQuantidadeMovimentacoesPossiveisTabuleiro(Tabuleiro* tabuleiro)
{
	// Quantidade de movimentações possíveis
	short quantidadeMovimentacoes = 0;

	int iteratorLinha, iteratorColuna;
	
	// Percorre todas as posições do Tabuleiro à procura de possições vazias
	for(iteratorLinha = 0; iteratorLinha < retornaQuantidadeLinhasTabuleiro(tabuleiro); iteratorLinha++)
	{
		for(iteratorColuna = 0; iteratorColuna < retornaQuantidadeColunasTabuleiro(tabuleiro); iteratorColuna++)
		{
			if(retornaEstadoPosicaoTabuleiro(tabuleiro, iteratorLinha, iteratorColuna) == VAZIA)
			{
				// Verifica os possíveis movimentos
				Movimento* movimento = (Movimento*)calloc(1, sizeof(Movimento));
				Posicao* posicao = (Posicao*)calloc(1, sizeof(Posicao));
				inicializaPosicao(posicao, iteratorLinha, iteratorColuna);
				inicializaMovimento(movimento, posicao, CIMA);
				
				// Verifica se é possível realizar as movimentações
				if(possivelMovimentar(tabuleiro, movimento))
				{
					quantidadeMovimentacoes++;
				}
				
				movimento->movimento = BAIXO;
				if(possivelMovimentar(tabuleiro, movimento))
				{
					quantidadeMovimentacoes++;
				}
				
				movimento->movimento = DIREITA;
				if(possivelMovimentar(tabuleiro, movimento))
				{
					quantidadeMovimentacoes++;
				}
				
				movimento->movimento = ESQUERDA;
				if(possivelMovimentar(tabuleiro, movimento))
				{
					quantidadeMovimentacoes++;
				}
				
				liberaEspacoMovimento(movimento);	
				liberaEspacoPosicao(posicao);
			}
		}
	}
	
	/*
	 Quantidade de moimentações possiveis na configuração do Tabuleiro apontado
	 pelo parâmetro.
	*/
	return quantidadeMovimentacoes;
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

