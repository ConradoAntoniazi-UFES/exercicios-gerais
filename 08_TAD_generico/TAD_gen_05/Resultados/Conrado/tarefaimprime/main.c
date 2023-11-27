#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int numTarefas;
    printf("Digite o numero de tarefas: ");
    scanf("%d\n", &numTarefas);

    tAgendaTarefas* agenda = CriaAgendaDeTarefas(numTarefas);

    for(int i = 0; i < numTarefas; i++) {
        char prefixo;
        int prioridade;

        scanf("%d %c ", &prioridade, &prefixo);

        if(prefixo == 'I') {
            char msg[100];
            scanf("%[^\n]", msg);
            tImpr* impr = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridade, impr, ExecutaTarefaImprimir, DestroiTarefaImprimir);

        } else if(prefixo == 'S') {
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tSoma* soma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);

        } else if(prefixo == 'M') {
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tMult* mult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);

        } else {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^0-9]");
            //corrigindo o contador do loop
            i--;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}
