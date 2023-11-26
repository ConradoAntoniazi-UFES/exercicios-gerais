#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

struct Aluno {
    char nome[50];
    float nota;
    char gen;
};

tAluno *CriaAluno() {
    tAluno* aluno = (tAluno*) malloc (sizeof(tAluno));

    if(aluno == NULL) {
        printf("Erro na alocacao dinamica - CriaAluno()\n");
        exit(1);
    }

    aluno->gen = '\0';
    aluno->nota = 0;

    return aluno;
}

void DestroiAluno(data_type aluno) {
    free(aluno);
}

void LeAluno(tAluno *aluno) {
    scanf("%*[^a-zA-Z]");
    int i = 0;
    char aux;
    while (1) {
        scanf("%c", &aux);

        if(aux == ';') break;

        aluno->nome[i] = aux;
        i++;
    }
    aluno->nome[i] = '\0';
    scanf("%c;%f", &aluno->gen, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    return aluno->gen;
}

float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}