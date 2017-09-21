
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

#ifndef ARVORE_H
#define	ARVORE_H

typedef struct arv *Arvore;
#include "pilha.h"
extern void in_ordem(Arvore raiz);
extern void pre_ordem(Arvore raiz);
extern void in_ordem2(Arvore raiz, FILE *arq2);
extern void pre_ordem2(Arvore raiz, FILE *arq2);
extern void pos_ordem(Arvore raiz);
extern void destroi_arvore(Arvore raiz);
extern Arvore criar_noh(char *valor, Arvore esq, Arvore dir);
extern void link(Arvore raiz, Arvore esq, Arvore dir);
extern void retira_pos_ordem_e_opera(Arvore raiz, Pilha p);
#endif	/* ARVORE_H */
