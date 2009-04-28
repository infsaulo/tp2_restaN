# Descrição: makefile define o que será construido pelo utilitário Make
# Autor: Saulo Marques Ribeiro Ricci

# Constrói todo o programa
all: posicao.o movimento.o main.o
	gcc -g -Wall -o testeMovimento *.o

# Roda o programa
run: all
	./testeMovimento

# Realiza uma limpeza dos arquivos de cada módulo criado
clean:
	rm teste* *.o *~
		
# Construção dos diferentes módulos do programa

# Módulos que constroem o TAD de Arvore Hash:

# Constrói o módulo posicao
posicao.o:
	gcc -g -c Posicao/Posicao.c -o posicao.o

movimento.o:
	gcc -g -c Movimento/Movimento.c -o movimento.o

main.o:
	gcc -g -c Movimento/testeMovimento.c -o main.o
