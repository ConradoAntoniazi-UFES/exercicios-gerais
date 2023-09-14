#include "jogada.h"
#include <stdio.h>

tJogada LeJogada() {
    tJogada jogada;

    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d", &jogada.x, &jogada.y) == 2) {
        jogada.sucesso = 1;
    }
    printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);

    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    return jogada.sucesso;
}