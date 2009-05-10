
/*
 Descrição:
 Ordenacao.c implementa as funções cujos protótipos estão definidos em 
 Ordencao.h
 
 Autor:
 Saulo Marques Ribeiro Ricci
 
 Data:
 06/05/2009
*/

#include "Ordenacao.h"
#include <stdlib.h>

//Refaz o heap
/*
 father é o índice de um suposto nó pai do heap, last é o índice do último 
 Ranking do array de Rankings apontado pelo terceiro parâmetro.
*/
void refaz(int father, int last, Ranking* rankings)
{
	//Variável que indica se o nó pai está na posição correta
	short wrong = 1;
    
	//Índice da posição de algum nó pai do heap
	int i = father + 1;
    
	//Índice do nó filho
	int j;
   
	Ranking* x;
	j = (i * 2) - 1;
	x = (Ranking*)calloc(1, sizeof(Ranking));
	copiaRanking(x, &rankings[i-1]);
    
	while ( j <= last ) 
	{ 
		if (j < last ) 
		{
			if(rankings[j].pontuacao < rankings[j+1].pontuacao)
			{
				j++;
			}
             
		}
        
		//O nó pai está na posição certa, logo não contraria a regra do heap
		if(x->pontuacao >= rankings[j].pontuacao)
		{
			wrong = 0;
			liberaEspacoSnapshot(rankings[i-1].snapshot);
			copiaRanking(&rankings[i-1], x);
			liberaEspacoRanking(x);
	   	return;
		}
        
        
		//Verifica se o pai está na posição correta
		if( wrong == 1 )
		{
			//O nó pai está na posição errada, logo contraria o princípio do heap
			liberaEspacoSnapshot(rankings[i-1].snapshot);
			copiaRanking(&rankings[i-1], &rankings[j]);
		}
		i = j + 1; 
		j = (i * 2) - 1 ;
        
	}
	
	liberaEspacoSnapshot(rankings[i-1].snapshot);
	copiaRanking(&rankings[i-1], x);
	
	liberaEspacoRanking(x);  
}

//Função que constrói o heap
/*
 rankings é o vetor de Ranking, n é a quantidade de Ranking.
*/
void constroi(Ranking* rankings, int *n)
{ 
	//Posição de um nó pai
	int Esq;
    
	Esq = *n / 2;
    
	//Laço que refaz todo o heap
	while ( Esq > 0 ) 
	{
		Esq--;
		refaz( Esq, (*n) - 1, rankings);
	}
}

//Método de ordenação HeapSort
void heapsort(Ranking* rankings, int quantidade)
{
	//Índices de contole para ordenação
	int Esq, Dir;
	Ranking* x;
	constroi(rankings, &quantidade);   /* constroi o heap */
	Esq = 0;
	Dir = quantidade - 1;
  
	//Laço de ordenação
	while ( Dir > 0 ) 
	{   
		/* ordena o vetor */
		x = (Ranking*)calloc(1, sizeof(Ranking)); 
		copiaRanking(x, &rankings[0]);
		liberaEspacoSnapshot(rankings[0].snapshot);
		copiaRanking(&rankings[0], &rankings[Dir]);
		liberaEspacoSnapshot(rankings[Dir].snapshot);
		copiaRanking(&rankings[Dir], x);
		Dir--;
		refaz( Esq, Dir, rankings);
		liberaEspacoRanking(x);
	}
}
