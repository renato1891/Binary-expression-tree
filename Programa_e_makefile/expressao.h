
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
#ifndef EXPRESSAO_H
#define	EXPRESSAO_H
#include "arvore.h"
extern void constroi_arvore_printa_e_calcula(char *expressao,FILE *arq2);
extern void printa_arvore(Arvore p, FILE *arq2);
extern float compara_operador_e_opera(char *operador, float num1, float num2);
#endif	/* EXPRESSAO_H */
