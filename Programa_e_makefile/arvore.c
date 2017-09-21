
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

struct arv{
	int bol;
	float numero;
	char operador[2];
	Arvore esq;
	Arvore dir;
};


void in_ordem(Arvore raiz){  /* Faz o encaminhamento in ordem colocando os parenteses*/
	
	if(raiz != NULL){
	printf("(");	
	in_ordem(raiz->esq);
	if(raiz->bol==1)
			printf("%f ",raiz->numero);
		else
			printf("%s ", raiz->operador);
	in_ordem(raiz->dir);
	printf(")");

	}
}


void pre_ordem(Arvore raiz){   /* Faz o encaminhamento pre ordem */
	
	if(raiz != NULL){
		if(raiz->bol==1)
			printf("%f ",raiz->numero);
		else
			printf("%s ", raiz->operador);
	pre_ordem(raiz->esq);
	pre_ordem(raiz->dir);
	

	}

}

void in_ordem2(Arvore raiz, FILE *arq2){   /* Faz o encaminhamento in ordem colocando os parenteses quando a saída for no arquivo*/
	
	if(raiz != NULL){
	fprintf(arq2,"(");	
	in_ordem2(raiz->esq,arq2);
	if(raiz->bol==1)
			fprintf(arq2,"%f ",raiz->numero);
		else
			fprintf(arq2,"%s ", raiz->operador);
	in_ordem2(raiz->dir,arq2);
	fprintf(arq2,")");

	}
}


void pre_ordem2(Arvore raiz, FILE *arq2){  /* Faz o encaminhamento pre ordem com saída do arquivo*/
	
	if(raiz != NULL){
		if(raiz->bol==1)
			fprintf(arq2,"%f ",raiz->numero);
		else
			fprintf(arq2,"%s ", raiz->operador);
	pre_ordem2(raiz->esq,arq2);
	pre_ordem2(raiz->dir,arq2);
	

	}

}



void pos_ordem(Arvore raiz){
	
	if(raiz != NULL){
	pos_ordem(raiz->esq);
	pos_ordem(raiz->dir);
	printf("%f", raiz->numero);
	

	}

}


void destroi_arvore(Arvore raiz){  /*Destroi os nós da arvore pelo encaminhamento pos ordem*/
	
	if(raiz != NULL){
	destroi_arvore(raiz->esq);
	destroi_arvore(raiz->dir);
	free(raiz);
	raiz = NULL;
	}

}
/*
int altura(Arvore raiz){
	int hd, he;
	if(raiz==NULL)
	return -1;
	he = altura(raiz->esq);
	hd = altura(raiz->dir);
	if(hd>he)
	return 1 + hd;
	else
	return 1 + he;

}
*/

Arvore criar_noh(char *valor, Arvore esq, Arvore dir){   
	Arvore novo_noh;
        char letra = valor[0];
	novo_noh = (Arvore) malloc (sizeof(struct arv));
	if(isdigit(letra)){
		novo_noh->bol = 1;
		novo_noh->numero = atof(valor);
		novo_noh->dir= dir;
		novo_noh->esq= esq;
		return novo_noh;
	}
	novo_noh->bol = 0;
	novo_noh->operador[0] = valor[0];
	novo_noh->dir= dir;
	novo_noh->esq= esq;
	return novo_noh;
}



void retira_pos_ordem_e_opera(Arvore raiz, Pilha p){ /*aqui será retirado os nos das árvore e feita as operações da pilha que contém os pontos flutuantes inserido*/
	
	if(raiz != NULL){
	retira_pos_ordem_e_opera(raiz->esq, p);
	retira_pos_ordem_e_opera(raiz->dir, p);
	if(raiz->bol==1){             /*caso seja um número*/
		InserePilha(p, raiz->numero);
	
	} else{
		float num2 =ProcessaPilha(p); /*caso não seja um número, será retirado os dois elementos da piklha e feito a operação de acordo com o operador enontrado*/
		float num1 =ProcessaPilha(p);
		float resultado = compara_operador_e_opera(raiz->operador, num1, num2);
		InserePilha(p,resultado);
		}	
	}
	
}

