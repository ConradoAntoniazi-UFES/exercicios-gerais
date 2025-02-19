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
    
    while(!AcabouJogo(jogo)) {
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro); //jogada jogador 1
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
            printf("JOGADOR 1 Venceu!\n");
            break;
        }
        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }
        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro); //jogada jogador 2
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
            printf("JOGADOR 2 Venceu!\n");
            break;
        }
        if(AcabouJogo(jogo)) {
            printf("Sem vencedor!\n");
            break;
        }
    }
}

int AcabouJogo(tJogo jogo) {
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)) return 1;

    return 0;
}

int ContinuaJogo() {
    char acao = '\0';

    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &acao);

    if(acao == 's') return 1;
    else return 0;
}