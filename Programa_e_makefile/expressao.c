
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"
#include "arvore.h"
#include "expressao.h"
#include "pilha_arvore.h"

void constroi_arvore_printa_e_calcula(char *expressao,FILE *arq2){  /*aqui seŕa um função que fará as manipulações para contruir a árvore, printá-la e depois fazer as operações. E por fim, chamar funções para destruir as pilhas e arvores. Essa função pode ser considerada o "main do trabalho", pois ela que chama as principais funções das demais TADs */
	char *unidade, letra;
	unidade = strtok(expressao," ");
	Pilha_arv p = CriaPilha_arv();
	while(unidade!=NULL){
            letra = unidade[0];
		if(isdigit(letra)){
			InserePilha_arv(p,criar_noh(unidade,NULL,NULL));
		} else{
                
        Arvore dir = ProcessaPilha_arv(p);
  		Arvore esq = ProcessaPilha_arv(p);
  		Arvore noh = criar_noh(unidade,esq,dir);
  		InserePilha_arv(p,noh);
  		}		
		unidade = strtok(NULL," ");
	}
	
	Arvore arvore = ProcessaPilha_arv(p);
	DestroiPilha_arv(p);
	printa_arvore(arvore,arq2);
	Pilha p2 = CriaPilha();
	retira_pos_ordem_e_opera(arvore, p2);
	if(arq2==NULL)
		printf("\nResultado: %f\n\n",ProcessaPilha(p2)); 
	else
		fprintf(arq2, "\nResultado: %f\n\n", ProcessaPilha(p2));
	DestroiPilha(p2);
	destroi_arvore(arvore);
	return;

}


void printa_arvore(Arvore p, FILE *arq2){
	if(arq2==NULL){
		printf("Pre Ordem: ");
		pre_ordem(p);
		printf("\n");
		printf("In Ordem: ");
		in_ordem(p);
		return;
	}
	fprintf(arq2,"Pre Ordem: ");
	pre_ordem2(p,arq2);
	fprintf(arq2,"\n");
	fprintf(arq2,"In Ordem: ");
	in_ordem2(p,arq2);
	return;
}


float compara_operador_e_opera(char *operador, float num1, float num2){  /*Aqui as operações serão feitas de acordo com o operador*/
	if(operador[0]=='+'){ 
		float resultado = num1 + num2;
		return resultado;
	}
	if(operador[0]=='-'){
		float resultado = num1 -num2;
		return resultado;
	}
	if(operador[0]=='*'){
		float resultado = num1 * num2;
		return resultado;
	}
	if(operador[0]=='/'){
		float resultado = num1 /num2;
		return resultado;
	}
	return 0;
}










 