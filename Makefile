# Descrição: makefile define o que será construido pelo utilitário Make
# Autor: Saulo Marques Ribeiro Ricci

# Constrói todo o programa
all: posicao.o movimento.o filaPos.o main.o
	gcc -g -Wall -o testeFila *.o

# Roda o programa
run: all
	./testeFila

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

filaPos.o:
	gcc -g -c FilaPos/FilaPos.c -o filaPos.o

main.o:
	gcc -g -c FilaPos/testeFilaPos.c -o main.o
