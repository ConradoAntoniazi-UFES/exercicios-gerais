#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

struct circulo
{
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r) {
    tCirculo circulo = (tCirculo) malloc (sizeof(struct circulo));

    if(circulo == NULL) {
        printf("Erro na alocacao dinamica\n");
        exit(1);
    }

    tPonto centro = Pto_Cria(x, y);
    Circulo_Atribui_Centro(circulo, centro);
    Circulo_Atribui_Raio(circulo, r);
    
    return circulo;
}

void Circulo_Apaga (tCirculo c) {
    if(c != NULL) {
        Pto_Apaga(c->centro);
        free(c);
    }
}

tPonto Circulo_Acessa_Centro (tCirculo c) {
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c) {
    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p) {
    c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r) {
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p) {
    if(Pto_Distancia(c->centro, p) > c->raio) return 0;

    return 1;
}