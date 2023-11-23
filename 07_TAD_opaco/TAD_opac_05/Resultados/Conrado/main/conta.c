#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta {
    tUsuario* user;
    int numConta;
    float saldo;
};

tConta *CriaConta() {
    tConta* conta = (tConta*) malloc (sizeof(tConta));

    if(conta == NULL) {
        printf("Erro na alocacao dinamica - CriaConta()\n");
        exit(1);
    }

    conta->user = CriaUsuario();
    conta->numConta = 0;
    conta->saldo = 0;

    return conta;
}

void DestroiConta(tConta *conta) {
    if(conta != NULL) {
        DestroiUsuario(conta->user);
        free(conta);
    }
}

void LeConta(tConta *conta) {
    LeUsuario(conta->user);
    scanf("%d\n", &conta->numConta);
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numConta);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    if(conta->numConta == numero) return 1;

    return 0;
}

void SaqueConta(tConta *conta, float valor) {
    if(conta->saldo >= valor) conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if(origem->saldo >= valor) {
        DepositoConta(destino, valor);
        SaqueConta(origem, valor);
    }
}