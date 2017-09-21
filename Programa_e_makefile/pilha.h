
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

#ifndef PILHA_H
#define	PILHA_H

typedef struct PILHA *Pilha;
typedef struct NODO *Nodo;

extern Pilha CriaPilha(void);
extern int PilhaVazia (Pilha p);
extern void InserePilha (Pilha p,float valor);
extern float ProcessaPilha (Pilha p);
extern float ConsultaPilha (Pilha p);
extern void DestroiPilha (Pilha p);
#endif	/* PILHA_H */
