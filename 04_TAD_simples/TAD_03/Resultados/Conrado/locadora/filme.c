#include "filme.h"
#include <string.h>
#include <stdio.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme lerFilme () {
    int codigo;
    char nome[MAX_CARACTERES];
    int valor;
    int quantidade;

    scanf("%*[^0-9]");
    scanf("%d,", &codigo);
    scanf("%^[,],", nome);
    scanf("%d,%d", &valor, &quantidade);

    tFilme filme;

    filme = criarFilme(nome, codigo, valor, quantidade);

    return filme;
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
    return strcmp(filme1.nome, filme2.nome);
}