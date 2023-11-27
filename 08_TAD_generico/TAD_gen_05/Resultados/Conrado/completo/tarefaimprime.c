#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr {
    char* msg;
};

tImpr* CriaTarefaImprimir(char *msg) {
    tImpr* m = (tImpr*) malloc (sizeof(tImpr));

    if(m == NULL) {
        printf("Erro na alocacao dinamica - CriaTarefaImprimir(char *msg)\n");
        exit(1);
    }

    m->msg = (char*) malloc (sizeof(char) * strlen(msg) + 1);
    strcpy(m->msg, msg);

    return m;
}

void ExecutaTarefaImprimir(void *imp) {
    tImpr* imprimir = (tImpr*) imp;

    printf("\n%s", imprimir->msg);
}

void DestroiTarefaImprimir(void *imp) {
    tImpr* imprimir = (tImpr*) imp;
    free(imprimir->msg);
    free(imprimir);
}