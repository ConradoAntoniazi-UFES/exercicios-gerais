#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char* nome; /**< Ponteiro para nome do aluno, que será alocado dinamicamente*/
    int matricula; /**< Matrícula do aluno */
    int n1, n2, n3; /**< Notas das avaliações */
};


tAluno* CriaAluno() {
    tAluno* aluno;

    aluno = (tAluno*) malloc(sizeof(tAluno));

    if(aluno == NULL) {
        printf("Deu pau na CriaAluno (alocacao)\n");
        exit(1);
    }

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

void ApagaAluno(tAluno *aluno) {
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno) {
    int tam_nome = 0;
    int caractere;

    scanf("%*[^A-Za-z]");

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
        tam_nome++;
        aluno->nome = realloc(aluno->nome, tam_nome);

        if(aluno->nome == NULL) {
            printf("Deu pau na LeAluno (alocacao)\n");
            exit(1);
        }

        aluno->nome[tam_nome - 1] = caractere;
    }
    tam_nome++;
    aluno->nome = realloc(aluno->nome, tam_nome);
    aluno->nome[tam_nome - 1] = '\0';

    scanf("%d %d %d %d", &aluno->matricula, &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    if(aluno1->matricula > aluno2->matricula) return 1;
    else if(aluno1->matricula == aluno2->matricula) return 0;
    else return -1;
}

int CalculaMediaAluno(tAluno* aluno) {
    return (aluno->n1 + aluno->n2 + aluno->n3) / 3;
}

int VerificaAprovacao(tAluno* aluno) {
    if(CalculaMediaAluno(aluno) >= 7) return 1;

    return 0;
}

void ImprimeAluno(tAluno* aluno) {
    printf("%s", aluno->nome);
    printf("\n");
}