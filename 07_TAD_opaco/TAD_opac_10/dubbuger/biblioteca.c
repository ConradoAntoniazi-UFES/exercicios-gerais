#include "livro.h"
#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

struct Biblioteca {
    tLivros** livros;
    int numLivros;
};

tBiblioteca* InicializarBiblioteca() {
    tBiblioteca* biblioteca = (tBiblioteca*) malloc (sizeof(tBiblioteca));

    biblioteca->livros = (tLivros**) malloc (sizeof(tLivros*));
    biblioteca->numLivros = 0;

    return biblioteca;
}

void ApagaBiblioteca(tBiblioteca* biblioteca) {
    if(biblioteca != NULL) {
        for(int i = 0; i < biblioteca->numLivros; i++) {
            ApagaLivro(biblioteca->livros[i]);
        }
        free(biblioteca->livros);
        free(biblioteca);
    }
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro) {
    if(biblioteca->numLivros == 0) {
        (biblioteca->numLivros)++;
        biblioteca->livros[0] = livro;

    } else {
        (biblioteca->numLivros)++;
        biblioteca->livros = (tLivros**) realloc (biblioteca->livros, biblioteca->numLivros * sizeof(tLivros*));
        biblioteca->livros[biblioteca->numLivros - 1] = livro;
    }
    printf("Livro adicionado com sucesso!\n");
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo) {
    for(int i = 0; i < biblioteca->numLivros; i++) {
        if(!VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo)) {
            for(int c = i + 1; c < biblioteca->numLivros; c++) {
                biblioteca->livros[c - 1] = biblioteca->livros[c];
            }
            (biblioteca->numLivros)--;
            ApagaLivro(biblioteca->livros[biblioteca->numLivros]);
            biblioteca->livros = (tLivros**) realloc (biblioteca->livros, sizeof(tLivros*) * biblioteca->numLivros);
            printf("Livro removido com sucesso!\n");
            return;
        } 
    }
    printf("Livro nao encontrado na biblioteca.\n");
}

int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo) {
    return strcmp(getTitulo(livro), titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca) {
    if(biblioteca->numLivros == 0) {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    ImprimeLivro(biblioteca->livros[0]);

    printf("\nLista de Livros na Biblioteca:\n");
    for(int i = 0; i < biblioteca->numLivros; i++) {
        ImprimeLivro(biblioteca->livros[i]);
    }
}