#include "locadora.h"

tLocadora criarLocadora () {
    tLocadora locadora;

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
    
}

tLocadora lerCadastroLocadora (tLocadora locadora) {

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