#include "usuario.h"
#include <string.h>
#include <stdio.h>

tUsuario CriaUsuario(char nome[20], char cpf[15]) {
    tUsuario usuario;

    strcpy(usuario.nome, nome);
    strcpy(usuario.cpf, cpf);

    return usuario;    
}

void ImprimeUsuario(tUsuario user) {
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n\n", user.cpf);
}