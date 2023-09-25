#include "locadora.h"
#include <string.h>
#include <stdio.h>

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
        if(verificarFilmeCadastrado(locadora, codigo)){
            printf("Filme ja cadastrado no estoque\n");
        }
        else{
            locadora.filme[locadora.numFilmes] = criarFilme(nome, codigo, valor, quantidade);
        }
    }
    locadora.numFilmes++;

    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora) {
    tFilme filme = lerFilme();
    

    //cadastrarFilmeLocadora(locadora,);
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    for(int i = 0; i < quantidadeCodigos; i++) {
        if(verificarFilmeCadastrado(locadora, codigos[i])){
            for(int c = 0; c < locadora.numFilmes; c++) {
                if(codigos[i] == obterCodigoFilme(locadora.filme[c])) {
                    alugarFilme(locadora.filme[c]);
                }
            }
        }
    }

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora) {
    int cont = 0;
    int codigos[101];

    while (scanf("%d\n", codigos[cont]) == 1) cont++;

    locadora = alugarFilmesLocadora(locadora, codigos, cont);

    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    for(int i = 0; i < quantidadeCodigos; i++) {
        if(verificarFilmeCadastrado(locadora, codigos[i])){
            for(int c = 0; c < locadora.numFilmes; c++) {
                if(codigos[i] == obterCodigoFilme(locadora.filme[c])) {
                    devolverFilme(locadora.filme[c]);
                }
            }
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    int cont = 0;
    int codigos[101];

    while (scanf("%d\n", codigos[cont]) == 1) cont++;

    locadora = devolverFilmesLocadora(locadora, codigos, cont);

    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora) {
    
}

void consultarEstoqueLocadora (tLocadora locadora) {

}

void consultarLucroLocadora (tLocadora locadora) {

}