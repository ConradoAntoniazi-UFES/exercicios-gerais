#include "vetor.h"
#include <stdio.h>

int Soma(int a, int b) {
    return a + b;
}

int Multiplica(int a, int b) {
    return a * b;
}

int main() {
    Vetor vetor;

    LeVetor(&vetor);

    Operation op = Soma;

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, op));

    op = Multiplica;

    printf("Produto: %d", AplicarOperacaoVetor(&vetor, op));

    return 0;
}