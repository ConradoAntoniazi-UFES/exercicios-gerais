#include "conta.h"
#include "banco.h"
#include <stdlib.h>
#include <stdio.h>

struct Banco {
    tConta** contasBanco;
    int numContas;
};

tBanco* CriaBanco() {
    tBanco* banco = (tBanco*) malloc (sizeof(tBanco));

    if(banco == NULL) {
        printf("Erro na alocacao dinamica - CriaBanco\n");
        exit(1);
    }

    banco->numContas = 0;
    banco->contasBanco = (tConta**) malloc (sizeof(tConta*));

    return banco;
}

void DestroiBanco(tBanco *banco) {
    if(banco != NULL) {
        for(int i = 0; i < banco->numContas; i++) {
            DestroiConta(banco->contasBanco[i]);
        }
        free(banco->contasBanco);
        free(banco);
    }
}

void AbreContaBanco(tBanco *banco) {
    (banco->numContas)++;

    banco->contasBanco = (tConta**) realloc (banco->contasBanco, sizeof(tConta*) * banco->numContas);
    banco->contasBanco[banco->numContas - 1] = CriaConta();
    LeConta(banco->contasBanco[banco->numContas - 1]);
}

void SaqueContaBanco(tBanco *banco) {
    int numConta = -1;
    float valor = 0;

    scanf("%d %f\n", &numConta, &valor);
    
    for(int i = 0; i < banco->numContas; i++) {
        if(VerificaConta(banco->contasBanco[i], numConta)) {
            SaqueConta(banco->contasBanco[i], valor);
            return;
        }
    }
}

void DepositoContaBanco(tBanco *banco) {
    int numConta = -1;
    float valor = 0;

    scanf("%d %f\n", &numConta, &valor);
    
    for(int i = 0; i < banco->numContas; i++) {
        if(VerificaConta(banco->contasBanco[i], numConta)) {
            DepositoConta(banco->contasBanco[i], valor);
            return;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco) {
    int numContaOrigem = -1, numContaDestino = -1;
    float valor = 0;

    scanf("%d %d %f\n", &numContaOrigem, &numContaDestino, &valor);
    
    for (int i = 0; i < banco->numContas; i++) {
        if (VerificaConta(banco->contasBanco[i], numContaOrigem)) {
            for (int c = 0; c < banco->numContas; c++) {
                if (VerificaConta(banco->contasBanco[c], numContaDestino)) {
                    TransferenciaConta(banco->contasBanco[i], banco->contasBanco[c], valor);
                    return;
                }
            }
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->numContas; i++) {
        if(banco->contasBanco[i] != NULL) {
            ImprimeConta(banco->contasBanco[i]);
        }
    }
}