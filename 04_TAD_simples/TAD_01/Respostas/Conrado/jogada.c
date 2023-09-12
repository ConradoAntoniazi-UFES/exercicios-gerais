#include "jogada.h"
#include <stdio.h>

tJogada LeJogada() {
    
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