#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("%d ", n[i]);
        if(i == tam -1) {
            printf("\n");
        }
    }
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    int j, aux;

    for(j = *paraTrocar + 1; j < tam; j++) {

        if(vet[j] < vet[*paraTrocar]) {
            aux = vet[j];
            vet[j] = vet[*paraTrocar];
            vet[*paraTrocar] = aux;
            //*paraTrocar = j;
        }
    }    
}

void OrdeneCrescente(int * vet, int tam) {
    int i = 0, menor = 0;
    int *p_indice;

    p_indice = &i;

    for(i = 0; i < tam; i++) {

        TrocaSeAcharMenor(vet, tam, p_indice);
    }

}