
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

struct PILHA_ARV {
    int tam;
    Nodo_arv inicio;
    Nodo_arv final;
};

struct NODO_ARV{
    Arvore noh;
    Nodo_arv prox;
};

Pilha_arv CriaPilha_arv(void) {
    Pilha_arv p = (Pilha_arv) malloc (sizeof (struct PILHA_ARV));
    p->inicio = NULL;
    p->final = NULL;
    p->tam =0;
    return(p);
}

int Pilha_arv_Vazia(Pilha_arv p){
    if (p->tam == 0){
        return 1;
    }
    return 0;
}

void InserePilha_arv(Pilha_arv p, Arvore noh){
    if (Pilha_arv_Vazia(p)){
       Nodo_arv aux = (Nodo_arv) malloc (sizeof(struct NODO_ARV));
       p->inicio = aux;
       p->final = aux;
       p->tam++;
       aux->prox = NULL;
       aux->noh = noh;
       return;
    }
      Nodo_arv aux = (Nodo_arv) malloc (sizeof(struct NODO_ARV));
      aux->noh = noh;
      aux->prox = p->final->prox;
      p->final->prox = aux;
      p->final = aux;
      p->tam++;
      return;
}

Arvore ProcessaPilha_arv(Pilha_arv p){
    if (!Pilha_arv_Vazia(p)){
        if(p->inicio==p->final){
            Arvore noh = p->inicio->noh;
            free(p->inicio);
            p->inicio = NULL;
            p->final =NULL;
            p->tam--;
            return (noh);
        }
        Nodo_arv aux = p->inicio;
        while(aux->prox != p->final)
        aux = aux->prox;        
        Arvore noh = p->final->noh;
        p->final = aux;
        free (aux->prox);
        aux->prox = NULL;
        p->tam--;
        return (noh);
    }
  return NULL;
}

    
void DestroiPilha_arv(Pilha_arv p){
    if (p->tam > 0){
        ProcessaPilha_arv(p);
    }
    free (p);
    return;
}  


