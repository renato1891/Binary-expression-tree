all:
	gcc -Wall -o arvore.o -c arvore.c
	gcc -Wall -o pilha_arvore.o -c pilha_arvore.c
	gcc -Wall -o pilha.o -c -lm pilha.c
	gcc -Wall -o expressao.o -c -lm expressao.c
	gcc -Wall -o main arvore.o pilha_arvore.o pilha.o expressao.o main.c
run:
	./main
