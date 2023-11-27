#ifndef _TAREFA_H
#define _TAREFA_H

typedef void (*FptrExecutaTarefa)(void* tarefa);

typedef void (*FptrFinalizaTarefa)(void* tarefa);

typedef struct tarefa tTarefa;

tTarefa* CriaTarefa(int prioridade, void* funcao, FptrExecutaTarefa funcExecutaTarefa, FptrFinalizaTarefa funcFinalizaTarefa);

int GetPrioridade (tTarefa* tarefa);

void ExecutaTarefa(tTarefa* tarefa);

void DestroiTarefa(tTarefa* tarefa);

#endif