#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto
{
    float x;
    float y;
};

tPonto Pto_Cria (float x, float y) {
    tPonto p = (tPonto) malloc (sizeof(struct ponto));

    if(p == NULL) {
        printf("Erro na alocacao dinamica\n");
        exit(1);
    }

    p->x = x;
    p->y = y;
    
    return p;
}

void Pto_Apaga (tPonto p) {
    if(p != NULL) {
        free(p);
    }
}

float Pto_Acessa_x (tPonto p) {
    return p->x;
}

float Pto_Acessa_y (tPonto p) {
    return p->y;
}

void Pto_Atribui_x (tPonto p, float x) {
    p->x = x;
}

void Pto_Atribui_y (tPonto p, float y) {
    p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2) {
    float diff_x = Pto_Acessa_x(p2) - Pto_Acessa_x(p1);
    float diff_y = Pto_Acessa_y(p2) - Pto_Acessa_y(p1);
    float dist = sqrt(pow(diff_x, 2) + pow(diff_y, 2));

    return dist;
}