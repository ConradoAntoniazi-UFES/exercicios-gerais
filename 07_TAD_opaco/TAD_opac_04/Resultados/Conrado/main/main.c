#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void OrdemDeMatriculaAprovados(tAluno* alunos[], int num_alunos) {
    tAluno* aux;

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
    scanf("%d", &num_alunos);

    tAluno* alunos[num_alunos];

    for(int i = 0; i < num_alunos; i++) {
        alunos[i] = CriaAluno();

        LeAluno(alunos[i]);
    }

    OrdemDeMatriculaAprovados(alunos, num_alunos);

    for(int i = 0; i < num_alunos; i++) {
        if(VerificaAprovacao(alunos[i])) ImprimeAluno(alunos[i]);

        ApagaAluno(alunos[i]);
    }

    return 0;
}