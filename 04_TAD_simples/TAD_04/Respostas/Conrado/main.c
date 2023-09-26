#include "aluno.h"
#include <stdio.h>

void ImprimeEmOrdemDeMatriculaAprovados(tAluno alunos[], int num_aprovados) {
    tAluno aux;

    for(int i = 0; i < num_aprovados; i++) {
        for(int c = i + 1; c < num_aprovados; c++) {
            if(ComparaMatricula(alunos[c], alunos[i]) == -1) {
                aux = alunos[i];
                alunos[i] = alunos[c];
                alunos[c] = aux;
            }
        }
    }

    for(int i = 0; i < num_aprovados; i++) {
        ImprimeAluno(alunos[i]);
    }
}

int main() {
    int num_alunos = 0, num_aprovados = 0;

    scanf("%d", &num_alunos);
    tAluno alunos[num_alunos], aluno_aux; 

    for(int i = 0; i < num_alunos; i++) {
        alunos[i] = LeAluno();

        if(VerificaAprovacao(alunos[i])) {
            aluno_aux = alunos[num_aprovados];
            alunos[num_aprovados] = alunos[i];
            alunos[i] = aluno_aux;
            num_aprovados++;
        }
    }

    ImprimeEmOrdemDeMatriculaAprovados(alunos, num_aprovados);

    return 0;
}