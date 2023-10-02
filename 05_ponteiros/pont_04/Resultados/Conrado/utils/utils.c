#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho) {
    
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media) {
    float valor_media = 0, soma = 0;

    for(int i = 0; i < tamanho; i++) {
        if(i == 0) {
            *maior = array[i];
            *menor = array[i];
        }       
        soma += array[i];
        if(*maior < array[i]) {
            *maior = array[i];
        }

        if(*menor > array[i]) {
            *menor = array[i];
        }
    }
    valor_media = soma / (float)tamanho;
    *media = valor_media;
}