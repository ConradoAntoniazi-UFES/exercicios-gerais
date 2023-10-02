#include "evento.h"
#include <stdio.h>

void cadastrarEvento(Evento* eventos, int* numEventos) {
    Evento evento;

    if(*numEventos < MAX_EVENTOS) {
        scanf("%*[^A-Za-z]");
        scanf("%s", evento.nome);
        scanf("%d %d %d", &evento.dia, &evento.mes, &evento.ano);

        printf("Evento cadastrado com sucesso!\n");
    }
    else {
        printf("Limite de eventos atingido!\n");
        return;
    }

    eventos[*numEventos] = evento;
    (*numEventos)++;
}

void ImprimeEvento(Evento evento, int pos) {
    printf("%d - %s - %d/%d/%d\n", pos, evento.nome, evento.dia, evento.mes, evento.ano);
}

void exibirEventos(Evento* eventos, int* numEventos) {

    if(*numEventos == 0) {
        printf("Nenhum evento cadastrado.\n");
        return;
    }

    printf("Eventos cadastrados:\n");

    for(int i = 0; i < *numEventos; i++) {
        ImprimeEvento(eventos[i], i);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos) {
    int indice_evento;
    if(indice_evento > *numEventos || indice_evento < 0) {
        printf("Indice invalido!\n");
        return;
    }

    scanf("%d", &indice_evento);
    scanf("%d %d %d", &eventos[indice_evento].dia, &eventos[indice_evento].mes, &eventos[indice_evento].ano);
    printf("Data modificada com sucesso!");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento aux;

    if((*indiceA > *numEventos || *indiceA < 0) || (*indiceB > *numEventos || *indiceB < 0)) {
        printf("Indices invalidos!\n");
        return;
    }

    aux = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;

    printf("Eventos trocados com sucesso!\n");
}