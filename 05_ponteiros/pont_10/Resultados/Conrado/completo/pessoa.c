#include "pessoa.h"
#include <stdio.h>

tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {

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
        i++;
    }
    printf("\n");
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

        printf("IRMAO: ");
        if(pessoa->irmao != NULL) {
            ImprimeNome(pessoa->irmao);
        } else {
            printf("NAO INFORMADO\n");
        }

        printf("\n");
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai) {
        return 1;
    }
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int mae = 0, pai = 0, filho = 0, num;
    
    scanf("%d\n", &num);

    for(int c = 0; c < num; c++) {

        scanf("%*[^m]");
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

        if(mae != -1) {
            pessoas[filho].mae = &pessoas[mae];
        }
        if(pai != -1) {
            pessoas[filho].pai = &pessoas[pai];
        }
    }

    for(int i = 0; i < numPessoas - 1; i++) {
        for(int j = i + 1; j < numPessoas; j++) {
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])){
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}