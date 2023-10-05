#include "pessoa.h"
#include <stdio.h>

int main () {
    int num;

    scanf("%d\n", &num);

    tPessoa pessoas[num];

    for (int i = 0; i < num; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, num);

    for( int j = 0; j < num; j++) {
        ImprimePessoa(&pessoas[j]);
    }

    return 0;
}