#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n) {
    scanf("%d %d", m, n);
}

int EhPrimo(int n) {
    int i, cont = 0;
    
    for(i = 1; i <= n; i++) {
        if(n % i == 0) cont++;
    }

    if(cont == 2) return 1;

    return 0;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
    int i;
    *menor = 0;
    *maior = 0;

    for(i = m; i <= n; i++) {
        if(EhPrimo(i)) {
            if(*menor == 0) {
                *menor = i;
            }
            *maior = i;
        }
    }
}