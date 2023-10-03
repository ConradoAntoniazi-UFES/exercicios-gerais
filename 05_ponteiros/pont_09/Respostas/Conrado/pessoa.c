#include "pessoa.h"
#include <stdio.h>

tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    *pessoa = CriaPessoa();

    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    if(pessoa->pai != NULL || pessoa->mae != NULL) return 1;

    return 0;
}

void ImprimeNome(tPessoa *pessoa) {
    int i = 0;

    while (pessoa->nome[i] != '\0') {
        printf("%c", pessoa->nome[i]);
    }
}

void ImprimePessoa(tPessoa *pessoa) {
    if(VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: ");
        ImprimeNome(pessoa);
        
        printf("PAI: ");
        if(pessoa->pai != NULL) {
            ImprimeNome(pessoa->pai);
        } else {
            printf("NAO INFORMADO\n");
        }

        printf("MAE: ");
        if(pessoa->mae != NULL) {
            ImprimeNome(pessoa->mae);
        } else {
            printf("NAO INFORMADO\n");
        }
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {

}