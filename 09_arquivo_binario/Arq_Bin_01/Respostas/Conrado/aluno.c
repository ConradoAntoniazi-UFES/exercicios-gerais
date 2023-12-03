#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[101];
    char data_nasc[50];
    char curso[50];
    char periodo[7];
    int progresso;
    float CR;
};

Aluno** CriaVetorAlunos(int numeroAlunos) {
    Aluno** alunos = (Aluno**) malloc (sizeof(Aluno*) * numeroAlunos);

    if(alunos == NULL) {
        perror("Erro na alocacao dinamica do vetor de alunos\n");
        exit(EXIT_FAILURE);
    }

    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA) {
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));

    if(aluno == NULL) {
        perror("Erro na alocacao dinamica do ponteiro para aluno\n");
        exit(EXIT_FAILURE);
    }

    strcpy(aluno->nome, nome);
    strcpy(aluno->data_nasc, dtNasc);
    strcpy(aluno->curso, cursoUfes);
    strcpy(aluno->periodo, periodoIngresso);
    aluno->progresso = percConclusao;
    aluno->CR = CRA;

    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos) {
    for(int i = 0; i < numeroAlunos; i++) {
        scanf("%*[^A-Za-z]");
        scanf("%[^\n]\n", vetorAlunos[i]->nome);
        scanf("%[^\n]\n", vetorAlunos[i]->data_nasc);
        scanf("%[^\n]\n", vetorAlunos[i]->curso);
        scanf("%[^\n]\n", vetorAlunos[i]->periodo);
        scanf("%d\n%f", &vetorAlunos[i]->progresso, &vetorAlunos[i]->CR);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    if(alunos != NULL) {
        for(int i = 0; i < numeroAlunos; i++) {
            free(alunos[i]);
        }
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE* arquivo = fopen(fileName, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para salvar");
        exit(EXIT_FAILURE);
    }

    fwrite(&numeroAlunos, sizeof(int), 1, arquivo);

    for(int i = 0; i < numeroAlunos; i++) {
        fwrite(alunos[i], sizeof(Aluno), 1, arquivo);
    }

    fclose(arquivo);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE* arquivo = fopen(fileName, "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para abrir");
        exit(EXIT_FAILURE);
    }

    int numeroAlunos;

    fread(&numeroAlunos, sizeof(int), 1, arquivo);

    for(int i = 0; i < numeroAlunos; i++) {
        fread(alunos[i], sizeof(Aluno), 1, arquivo);
    }
    
    fclose(arquivo);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    for(int i = 0; i < numeroAlunos; i++) {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->data_nasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->progresso);
        printf("CRA: %.2f\n", alunos[i]->CR);
    }
}