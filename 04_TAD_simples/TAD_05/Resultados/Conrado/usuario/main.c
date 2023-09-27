#include "conta.h"
#include "usuario.h"
#include <stdio.h>

int main() {
    int acao = -1, numMaxCadastros = 0;

    scanf("%d", &numMaxCadastros);
    tConta contas[5];

    while (acao != 0) {
        scanf("%d", &acao);

        if(acao == 1) {
            float valor = 0; 
            int num_conta;

            scanf("%d", &num_conta);
            scanf("%f", &valor);

            contas[num_conta - 1] = SaqueConta(contas[num_conta - 1], valor);
            
        }
        else if (acao == 2) {
            float valor = 0; 
            int num_conta;

            scanf("%d", &num_conta);
            scanf("%f", &valor);

            contas[num_conta - 1] = DepositoConta(contas[num_conta - 1], valor);

        }
        else if (acao == 3) {
            char nome[50];
            char cpf[20];
            int num_conta = 0;

            scanf("%*[^a-zA-Z]");
            scanf("%[^ ]", nome);
            scanf(" %[^ ]", cpf);
            scanf("%d", &num_conta);

            contas[num_conta - 1] = CriaConta(num_conta, CriaUsuario(nome, cpf));
        }
        else if(acao == 4) {
            printf("===| Imprimindo Relatorio |===\n");
            for(int i = 0; i < numMaxCadastros; i++) {
                ImprimeConta(contas[i]);
            }
        }
    }
    
    return 0;
}