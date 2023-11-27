#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

struct soma {
    float num1;
    float num2;
    float resultado;
};

tSoma* CriaTarefaSoma(float n1, float n2) {
    tSoma* soma = (tSoma*) malloc (sizeof(tSoma));

    if(soma == NULL) {
        printf("Erro na alocacao na funcao CriaTarefaSoma(float n1, float n2)\n");
        exit(1);
    }

    soma->num1 = n1;
    soma->num2 = n2;
    soma->resultado =  n1 + n2;

    return soma;
}

void ExecutaTarefaSoma(void *sum) {
    tSoma* soma = (tSoma*)sum;

    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", soma->num1, soma->num2, soma->resultado);
}

void DestroiTarefaSoma(void *sum) {
    tSoma* soma = (tSoma*)sum;
    free(sum);
}