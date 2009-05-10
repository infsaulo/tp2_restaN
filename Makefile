# Descrição: makefile define o que será construido pelo utilitário Make
# Autor: Saulo Marques Ribeiro Ricci

# Constrói todo o programa
all: posicao.o movimento.o filaPos.o pilhaMov.o tabuleiro.o snapshot.o listaSnap.o metrica.o ordenacao.o jogo.o io.o main.o
	gcc -g -Wall -o restaN *.o

# Roda o programa
run: all
	./restaN -k 1 -e dados -s saida

# Realiza uma limpeza dos arquivos de cada módulo criado
clean:
	rm resta* teste* *.o *~
		
# Construção dos módulos que modelam o Jogo Resta_N

# Constrói o módulo do TAD Posicao
posicao.o:
	gcc -g -c Resta_N/Posicao/Posicao.c -o posicao.o

# Constrói o módulo do TAD Movimento
movimento.o:
	gcc -g -c Resta_N/Movimento/Movimento.c -o movimento.o

# Constrói o módulo do TAD FilaPos
filaPos.o:
	gcc -g -c Resta_N/FilaPos/FilaPos.c -o filaPos.o

# Constrói o módulo do TAD PilhaMov
pilhaMov.o:
	gcc -g -c Resta_N/PilhaMov/PilhaMov.c -o pilhaMov.o	

# Constrói o módulo do TAD Tabuleiro
tabuleiro.o:
	gcc -g -c Resta_N/Tabuleiro/Tabuleiro.c -o tabuleiro.o

# Constrói o TAD do módulo do TAD Snapshot
snapshot.o:
	gcc -g -c Resta_N/Snapshot/Snapshot.c -o snapshot.o

# Constrói o módulo do TAD ListaSnap
listaSnap.o:
	gcc -g -c Resta_N/ListaSnap/ListaSnap.c -o listaSnap.o

# Constrói o módulo do TAD Metrica
metrica.o:
	gcc -g -c Resta_N/Metrica/Metrica.c -o metrica.o

# Contrói o módulo das funções de ordenação por HeapSort
ordenacao.o:
	gcc -g -c Resta_N/Metrica/Ordenacao/Ordenacao.c -o ordenacao.o

# Constrói o módulo do TAD Jogo
jogo.o:
	gcc -g -c Resta_N/Jogo/Jogo.c -o jogo.o


# Construção do módulo de Entrada e Saída dos dados do sistema
io.o:
	gcc -g -c IO/io.c -o io.o

# Construção do módulo principal do sistema
main.o:
	gcc -g -c Principal/principal.c -o main.o
