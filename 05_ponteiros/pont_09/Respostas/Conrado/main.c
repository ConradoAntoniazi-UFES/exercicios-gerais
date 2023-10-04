#include "pessoa.h"
#include <stdio.h>

int main () {
    int num;

    scanf("%d\n", &num);

    tPessoa pessoas[num];

    for (int i = 0; i < num; i++) {
        LePessoa(pessoas[i]);
    }

    scanf("%d\n", &num);

    for(i = 0; i < num, i++) {
        AssociaFamiliasGruposPessoas(pessoas);
    }

    return 0;
}