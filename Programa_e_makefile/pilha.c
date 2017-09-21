
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

struct PILHA {
    int tam;
    Nodo inicio;
    Nodo final;
};

struct NODO{
    float valor;
    Nodo prox;
};

Pilha CriaPilha(void) {
    Pilha p = (Pilha) malloc (sizeof (struct PILHA));
    p->inicio = NULL;
    p->final = NULL;
    p->tam =0;
    return(p);
}

int PilhaVazia (Pilha p){
    if (p->tam == 0){
        return 1;
    }
    return 0;
}

void InserePilha (Pilha p,float valor){
    if (PilhaVazia(p)){
       Nodo aux = (Nodo) malloc (sizeof(struct NODO));
       p->inicio = aux;
       p->final = aux;
       p->tam++;
       aux->prox = NULL;
       aux->valor = valor;
       return;
    }
      Nodo aux = (Nodo) malloc (sizeof(struct NODO));
      aux->valor = valor;
      aux->prox = p->final->prox;
      p->final->prox = aux;
      p->final = aux;
      p->tam++;
      return;
}

float ProcessaPilha (Pilha p){
    if (!PilhaVazia(p)){
        if(p->inicio==p->final){
            float valor = p->inicio->valor;
            free(p->inicio);
            p->inicio = NULL;
            p->final =NULL;
            p->tam--;
            return (valor);
        }
        Nodo aux = p->inicio;
        while(aux->prox != p->final)
        aux = aux->prox;        
        float valor = p->final->valor;
        p->final = aux;
        free (aux->prox);
        aux->prox = NULL;
        p->tam--;
        return (valor);
    }
  return 0;
}
float ConsultaPilha (Pilha p){
    if (!PilhaVazia(p)){
        return (p->final->valor);
    }
  return 0;
}
    
void DestroiPilha (Pilha p){
    if (p->tam > 0){
        ProcessaPilha(p);
    }
    free (p);
}  