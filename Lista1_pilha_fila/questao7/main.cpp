#include <stdio.h>
#include <string.h>
//#include "pilha.h"

#define TAMANHO 50

struct pilha {
    char sinal[TAMANHO];
    char valor[TAMANHO];
    char expressao[TAMANHO];
    int t1; // topo para sinal
    int t2; // topo para valor
};

typedef struct pilha Pilha;

void inicializa(Pilha *p) {

    for (int i = 0; i < TAMANHO - 1; i++) {
        p->valor[i] = 0;
        p->sinal[i] = 0;
        p->expressao[i] = 0;
    }// esterilizando variáveis

    p->t1 = -1;
    p->t2 = -1;
    return;
}

void ver_cheia(Pilha *p) {
    if (p->t1 == TAMANHO - 1) {
        printf("Pilha cheia so cabe %d elementos \n", TAMANHO);
        return;
    }

    printf("Ainda cabe %d elementos \n", (TAMANHO - 1) - p->t1);
    return;
}

void ver_vazia(Pilha *p) {
    if (p->t1 <= -1) {
        printf("Pilha vazia, cabe %d elementos \n", TAMANHO);
    }
}

void insere_sinal(Pilha *p, char v) {
    if (p->t1 < TAMANHO - 1) {
        p->t1++;
        p->sinal[p->t1] = v;
        return;
    }

    ver_cheia(p);
    return;
}

void insere_valor(Pilha *p, char v) {
    if (p->t2 < TAMANHO - 1) {
        p->t2++;
        p->valor[p->t2] = v;
        return;
    }

    ver_cheia(p);
    return;
}

void retira_sinal(Pilha *p) {
    if (p->t1 <= -1) {
        ver_vazia(p);
        return;
    }

    p->sinal[p->t1] = 0;
    p->t1--;
    return;
}





void imprime_topo(Pilha *p) {
    printf("Topo %d \n", p->t1);
    return;
}

void hp12(Pilha *p) {

    if(strlen(p->expressao) >= TAMANHO)
    {
        printf("Sua expressao ultrapassou o limite de %d caracteres \n", TAMANHO);
        printf("voce digitou %d caracteres tente novamente com uma expressao menor\n", (int)strlen(p->expressao));
        return;
    }

    int i = 0;
    while (p->expressao[i] != 0) {

        if (p->expressao[i] != '+' &&
            p->expressao[i] != '-' &&
            p->expressao[i] != '*' &&
            p->expressao[i] != '/' &&
            p->expressao[i] != '(' &&
            p->expressao[i] != ')')
        {

            insere_valor(p, p->expressao[i]);
            if(p->expressao[i+1] == 0 || i+1 == TAMANHO)
            {
                while(p->t1 > -1)
                {
                    insere_valor(p, p->sinal[p->t1]);
                    retira_sinal(p);
                }
            }
        }
        else
        {
            if (p->expressao[i] != '(' && p->expressao[i] != ')')
            {
                insere_sinal(p, p->expressao[i]);
            }
            else
            {
                if(p->expressao[i] != '(')
                {
                    while(p->t1 > -1)
                    {
                        insere_valor(p, p->sinal[p->t1]);
                        retira_sinal(p);
                    }
                }
            }
        }
        i++;
    }
    printf("%s \n", p->valor);
    return;
}