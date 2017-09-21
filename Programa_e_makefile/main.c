
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: renato
 *
 * Created on 14 de Setembro de 2016, 16:48
 */
/*
Nome: Renato Borges Boaventura
matricula: 0021620
data 10/11/2016
Há os seguintes tipos de entradas e saídas:
in1 - para entrar com os dados via teclado
in2 - para entrar com os dados via arquivo
out1 - saída de dados na tela
out2 saída de dados em um arquivo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expressao.h"

/*
 * 
 */
int main(int argc, char** argv) {
	char expressao[2000];  
	if(argc< 3 && argc> 5)
		exit(1);
		if(!strcmp(argv[1], "in1")){
			printf("Digite a expressao: \n");
			fgets(expressao,2000,stdin);
			expressao[strlen(expressao)-1] = '\0';
      printf("\n");
      if(!strcmp(argv[2], "out1"))
				constroi_arvore_printa_e_calcula(expressao,NULL);
			if(!strcmp(argv[2], "out2")){
				FILE *arq2;
			  arq2 = fopen(argv[3], "w");
				constroi_arvore_printa_e_calcula(expressao,arq2);
				fclose(arq2);
			}

		}
		if(!strcmp(argv[1], "in2") && !strcmp(argv[3], "out1")){
			FILE *arq;
			arq = fopen(argv[2], "r");
			while( (fgets(expressao, sizeof(expressao)/sizeof(char), arq))!=NULL ){
				if(expressao[strlen(expressao)-1] == '\n')
					expressao[strlen(expressao)-1] = '\0';
      	printf("\n");
					constroi_arvore_printa_e_calcula(expressao,NULL);
			}
			fclose(arq);
		}
		if(!strcmp(argv[1], "in2") && !strcmp(argv[3], "out2")){
			FILE *arq;
			arq = fopen(argv[2], "r");
			FILE *arq2;
			arq2 = fopen(argv[4], "w");
			while( (fgets(expressao, sizeof(expressao)/sizeof(char), arq))!=NULL ){
				if(expressao[strlen(expressao)-1] == '\n')
					expressao[strlen(expressao)-1] = '\0';
					constroi_arvore_printa_e_calcula(expressao,arq2);
			}
			fclose(arq);
			fclose(arq2);
		}
	exit(0);
}




