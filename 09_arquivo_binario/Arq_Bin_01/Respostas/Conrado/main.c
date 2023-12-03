#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int numAlunos;
    scanf("%d", &numAlunos);

    Aluno** alunos = CriaVetorAlunos(numAlunos);

    
    return 0;
}
