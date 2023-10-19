#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void OrdemDeMatriculaAprovados(tAluno* alunos[], int num_alunos) {
    tAluno* aux;
    int num_aprovados;

    for(int i = 0; i < num_alunos; i++) {
        for(int j = i + 1; j < num_alunos; j++) {

            if(ComparaMatricula(alunos[i], alunos[j]) == 1) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

int main () {
    int num_alunos;
    int num_aprovados;
    scanf("%d", &num_alunos);

    tAluno* alunos[num_alunos];

    for(int i = 0; i < num_alunos; i++) {
        alunos[i] = CriaAluno();

        LeAluno(alunos[i]);

        if(VerificaAprovacao(alunos[i])) num_aprovados++;
    }

    for(int i = 0; i < num_aprovados; i++) {
        ImprimeAluno(alunos[i]);
    }

    return 0;
}