#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro() {
    tTabuleiro tabuleiro;
    int l, c;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro.posicoes[l][c] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    if(peca == 1 && EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    else if(peca == 2 && EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) tabuleiro.posicoes[y][x] = tabuleiro.peca2;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        for(c = 0; c < TAM_TABULEIRO; c++) {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, l, c)) return 1;
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    if(peca == 1 && tabuleiro.posicoes[x][y] == tabuleiro.peca1) return 1;
    else if(peca == 2 && tabuleiro.posicoes[x][y] == tabuleiro.peca2) return 1;
    else return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio) return 1;
    else return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    if((x >= 0 && x < TAM_TABULEIRO) && (y >=0 && y < TAM_TABULEIRO)) return 1;
    else return 0; 
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    int l, c;

    for(l = 0; l < TAM_TABULEIRO; l++) {
        printf("\t");
        for(c = 0; c < TAM_TABULEIRO; c++) {
            printf("%c", tabuleiro.posicoes[l][c]);
        }
        printf("\n");
    }
}