#include "filme.h"
#include <string.h>
#include <stdio.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;

    return filme;
}

tFilme lerFilme () {
    int codigo;
    char nome[20];
    int valor;
    int quantidade;

    scanf("%*[^0-9]");
    scanf("%d,", &codigo);
    scanf("%^[,],", nome);
    scanf("%d,%d", &valor, &quantidade);

    return criarFilme(nome, codigo, valor, quantidade);
}

int obterCodigoFilme (tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme) {
    int i = 0;

    while(filme.nome[i] != '\0') {
        printf("%c", filme.nome[i]);
        i++;
    }
}

int obterValorFilme (tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo) {
    if(obterCodigoFilme(filme) == codigo) return 1;
    return 0;
}

tFilme alugarFilme (tFilme filme) {
    filme.qtdAlugada++;
    filme.qtdEstoque--;

    return filme;
}

tFilme devolverFilme (tFilme filme) {
    filme.qtdAlugada--;
    filme.qtdEstoque++;

    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2) {
    if(strcmp(filme1.nome, filme2.nome) == 0) return 1;
    return 0;
}