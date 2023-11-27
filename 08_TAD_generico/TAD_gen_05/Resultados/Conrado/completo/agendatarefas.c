#include "agendatarefas.h"
#include "tarefa.h"
#include <stdlib.h>
#include <stdio.h>

struct agendatarefas {
    tTarefa** tarefas;
    int numTarefas;
    int tarefasCadastradas;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas* agenda = (tAgendaTarefas*) malloc (sizeof(tAgendaTarefas));

    if(agenda == NULL) {
        printf("Erro na alocacao dinamica - CriaAgendaTarefas()\n");
        exit(1);
    }

    agenda->numTarefas = numElem;
    agenda->tarefasCadastradas = 0;
    agenda->tarefas = (tTarefa**) malloc (sizeof(tTarefa*) * numElem);

    if(agenda->tarefas == NULL) {
        printf("Erro na alocacao dinamica - CriaAgendaTarefas() - agenda->tarefas\n");
        exit(1);
    }

    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    for(int i = 0; i < tar->numTarefas; i++) {
        DestroiTarefa(tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ) {
    tar->tarefas[tar->tarefasCadastradas] = CriaTarefa(prioridade, tarefa, executa, destroi);
    (tar->tarefasCadastradas)++;
}   

int Comparar(tTarefa* t1, tTarefa* t2){
    return(GetPrioridade(t2) - GetPrioridade(t1));
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {

    int troca = 1;
    while(troca){
        troca = 0;
        for(int i = 0; i < (tar->numTarefas - 1); i++){
            if(Comparar(tar->tarefas[i], tar->tarefas[i + 1]) > 0){
                tTarefa *temp = tar->tarefas[i];
                tar->tarefas[i] = tar->tarefas[i + 1];
                tar->tarefas[i + 1] = temp;
                troca = 1;
            }
        }
    }

    for(int i = 0; i < tar->numTarefas; i++) {
        ExecutaTarefa(tar->tarefas[i]);
    }
}