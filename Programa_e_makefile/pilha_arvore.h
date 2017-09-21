
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

#ifndef PILHA_ARVORE_H
#define	PILHA_ARVORE_H

typedef struct PILHA_ARV *Pilha_arv;
typedef struct NODO_ARV *Nodo_arv;

extern Pilha_arv CriaPilha_arv(void);
extern int Pilha_arv_Vazia(Pilha_arv p);
extern void InserePilha_arv(Pilha_arv p, Arvore noh);
extern Arvore ProcessaPilha_arv(Pilha_arv p);
extern void DestroiPilha_arv(Pilha_arv p);

#endif	/*  PILHA_ARVORE_H */
