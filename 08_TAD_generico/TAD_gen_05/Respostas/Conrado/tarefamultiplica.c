#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

struct mult {
    float n1, n2, result;
};

tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult* mult = (tMult*) malloc (sizeof(tMult));

    if(mult == NULL) {
        printf("Erro na alocacao dinamica - CriaTarefaMultiplicar(float n1, float n2)\n");
        exit(1);
    }

    mult->n1 = n1;
    mult->n2 = n2;
    mult->result = n1 * n2;

    return mult;
}

void ExecutaTarefaMultiplicar(void *mult) {
    tMult* multiplica = (tMult*)mult;

    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multiplica->n1, multiplica->n2, multiplica->result);
}

void DestroiTarefaMultiplicar(void *mult) {
    tMult* multiplica = (tMult*)mult;

    free(multiplica);
}
