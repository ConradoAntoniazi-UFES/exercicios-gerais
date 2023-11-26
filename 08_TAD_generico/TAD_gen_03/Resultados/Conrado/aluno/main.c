#include "aluno.h"
#include "relatorio.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int num_alunos = 0;
    Vector* alunos = VectorConstruct();

    scanf("%d", &num_alunos);

    for(int i = 0; i < num_alunos; i++) {
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos, (data_type) aluno);
    }

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos, DestroiAluno);

    return 0;
}
