#include "jogo.h"
#include <stdio.h>

tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}

void ComecaJogo(tJogo jogo) {

}

int AcabouJogo(tJogo jogo) {

}

int ContinuaJogo() {
    
}