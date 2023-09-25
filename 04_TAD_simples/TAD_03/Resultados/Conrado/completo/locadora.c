#include "locadora.h"
#include <string.h>

tLocadora criarLocadora () {
    tLocadora locadora;

    locadora.lucro = 0;
    locadora.numFilmes = 0;

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo) {
    int i;

    for(i = 0; i < MAX_FILMES; i++) {
        if(obterCodigoFilme(locadora.filme[i]) == codigo) return 1;
    }

    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade) {

    if(locadora.numFilmes == 0) {
        locadora.filme[0] = criarFilme(nome, codigo, valor, quantidade);
    } else {
        locadora.filme[locadora.numFilmes - 1] = criarFilme(nome, codigo, valor, quantidade);
    }
    locadora.numFilmes++;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    if(locadora.numFilmes == 0) {
        locadora.filme[0] = lerFilme();
    } else {
        locadora.filme[locadora.numFilmes - 1] = lerFilme();
    }
    locadora.numFilmes++;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

}

tLocadora lerAluguelLocadora (tLocadora locadora) {

}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

}

tLocadora lerDevolucaoLocadora (tLocadora locadora) {

}

tLocadora ordenarFilmesLocadora (tLocadora locadora) {

}

void consultarEstoqueLocadora (tLocadora locadora) {

}

void consultarLucroLocadora (tLocadora locadora) {

}