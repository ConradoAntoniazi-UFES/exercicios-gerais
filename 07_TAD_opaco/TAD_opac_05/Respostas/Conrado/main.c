#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    char acao;
    tBanco* banco = CriaBanco();

    while (1) {
        scanf("%c\n", &acao);

        if(acao == 'F') {
            DestroiBanco(banco);
            break;

        }
        else if (acao == 'A') {
            AbreContaBanco(banco);

        } else if (acao == 'D') {
            DepositoContaBanco(banco);

        } else if (acao == 'T') {
            TransferenciaContaBanco(banco);

        } else if (acao == 'S') {
            SaqueContaBanco(banco);

        } else if (acao == 'R') {
            ImprimeRelatorioBanco(banco);

        } else {
            printf("Operacao invalida\n");

        }
    }

    return 0;
}