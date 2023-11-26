#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    data_type* vetor;
    int tamanho;
};

Vector *VectorConstruct() {
    Vector* vetor = (Vector*) malloc (sizeof(Vector));

    if(vetor == NULL) {
        printf("Erro na alocacao do vetor\n");
        exit(1);
    }

    vetor->vetor = NULL;
    vetor->tamanho = 0;

    return vetor;   
}

void VectorPushBack(Vector *v, data_type val) {
    if(!v->tamanho) {
        v->vetor = (data_type*) malloc (sizeof(data_type));
        (v->tamanho)++;
        v->vetor[0] = val;
    }
    else {
        (v->tamanho)++;
        v->vetor = (data_type*) realloc (v->vetor, sizeof(data_type) * v->tamanho);
        v->vetor[v->tamanho - 1] = val;
    }
}

data_type VectorGet(Vector *v, int i) {
    return v->vetor[i];
}

int VectorSize(Vector *v) {
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    if(v != NULL) {
        if(v->vetor != NULL) {
            for(int i = 0; i < v->tamanho; i++) {
                destroy(v->vetor[i]);
            }
            free(v->vetor);
        }
        free(v);
    }
}