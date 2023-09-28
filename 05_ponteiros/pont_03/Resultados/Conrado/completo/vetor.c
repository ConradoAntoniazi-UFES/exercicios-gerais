#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        scanf("%d", vet[i]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam) {
    int i;

    for(i = 0; i < tam; i++) {
        printf("%d", n[i]);
    }
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar) {
    int i, aux;

    for(i = 0; i < tam; i++) {

        if(vet[i] < vet[*paraTrocar]) {
            aux = vet[i];
            vet[i] = vet[*paraTrocar];
            vet[*paraTrocar] = aux;
            *paraTrocar = i;
        }
    }    
}

void OrdeneCrescente(int * vet, int tam) {
    int i, menor = 0;


    for(i = 0; i < tam; i++) {

        //TrocaSeAcharMenor(vet, tam, &i);
    }

}