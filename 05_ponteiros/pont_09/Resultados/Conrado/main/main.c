#include "pessoa.h"
#include <stdio.h>

int main () {
    int num, num2;

    scanf("%d\n", &num);

    tPessoa pessoas[num];

    for (int i = 0; i < num; i++) {
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas);

    for( int j = 0; j < num; j++) {
        ImprimePessoa(&pessoas[j]);
    }

    return 0;
}