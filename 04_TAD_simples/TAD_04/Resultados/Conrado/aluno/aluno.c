#include "aluno.h"
#include <string.h>
#include <stdio.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3) {
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno() {
    tAluno aluno;

    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", aluno.nome);
    scanf("%d %d %d %d", &aluno.matricula, &aluno.n1, &aluno.n2, &aluno.n3);

    return CriaAluno(aluno.nome, aluno.matricula, aluno.n1, aluno.n2, aluno.n3);
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    if(aluno1.matricula == aluno2.matricula) return 0;
    else if(aluno1.matricula > aluno2.matricula) return 1;
    else return -1;
}

int CalculaMediaAluno(tAluno aluno) {
    int media;

    media = (aluno.n1 + aluno.n2 + aluno.n3) / 3;

    return media;
}

int VerificaAprovacao(tAluno aluno) {
    if(CalculaMediaAluno(aluno) >= 7) return 1;
    else return 0;
}

void ImprimeAluno(tAluno aluno) {
    int i = 0;

    while(aluno.nome[i] != '\0') {
        printf("%c", aluno.nome[i]);
        i++;
    }
    printf("\n");
}