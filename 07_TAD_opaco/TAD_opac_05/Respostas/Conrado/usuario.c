#include "usuario.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Usuario {
    char* nome;
    char* CPF;
};

tUsuario *CriaUsuario() {
    tUsuario* usuario = (tUsuario*) malloc (sizeof(tUsuario));

    if(usuario == NULL) {
        printf("ERRO NA ALOCACAO DINAMICA - CriaUsuario()\n");
        exit(1);
    }

    usuario->CPF = NULL;
    usuario->nome = NULL;
}

void DestroiUsuario(tUsuario *user) {
    if(user != NULL) {
        free(user->CPF);
        free(user->nome);
        free(user);
    }
}

void LeUsuario(tUsuario *user) {
    char aux[50];

    scanf("%*[^a-zA-Z]");
    scanf("%[^ ]", aux);
    user->nome = (char*) malloc ((sizeof(char) * strlen(aux)) + sizeof(char));
    strcpy(user->nome, aux);

    scanf("%*[^0-9]");
    scanf("%[^ ]", aux);
    user->CPF = (char*) malloc ((sizeof(char) * strlen(aux)) + sizeof(char));
    strcpy(user->CPF, aux);
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n\n", user->CPF);
}