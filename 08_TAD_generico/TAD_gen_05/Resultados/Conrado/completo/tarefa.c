#include "tarefa.h"
#include <stdlib.h>
#include <stdio.h>

struct tarefa {
    int prioridade;
    void* funcao;
    FptrExecutaTarefa funcExecutaTarefa;
    FptrFinalizaTarefa funcFinalizaFuncaoTarefa;
};

tTarefa* CriaTarefa(int prioridade, void* funcao, FptrExecutaTarefa funcExecutaTarefa, FptrFinalizaTarefa funcFinalizaTarefa) {
    tTarefa* tarefa = (tTarefa*) malloc (sizeof(tTarefa));

    if(tarefa == NULL) {
        printf("Erro na alocacao dinamica - CriaTarefa()\n");
        exit(1);
    }

    tarefa->funcao = funcao;
    tarefa->prioridade = prioridade;
    tarefa->funcExecutaTarefa = funcExecutaTarefa;
    tarefa->funcFinalizaFuncaoTarefa = funcFinalizaTarefa;

    return tarefa;
}

int GetPrioridade (tTarefa* tarefa) {
    return tarefa->prioridade;
}

void ExecutaTarefa(tTarefa* tarefa) {
    tarefa->funcExecutaTarefa(tarefa->funcao);
}

void DestroiTarefa(tTarefa* tarefa) {
    tarefa->funcFinalizaFuncaoTarefa(tarefa->funcao);
    free(tarefa);
}