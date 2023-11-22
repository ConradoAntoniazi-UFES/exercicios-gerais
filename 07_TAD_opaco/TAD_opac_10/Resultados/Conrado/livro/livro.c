#include "livro.h"
#include <stdlib.h>
#include <stdio.h>

struct Livros {
    char* titulo;
    char* autor;
    int ano;
};

tLivros* CriaLivro() {
    tLivros* livro = (tLivros*) malloc (sizeof(tLivros));

    if(livro == NULL) {
        printf("Erro na alocacao dinamica - CriaLivro()\n");
        exit(1);
    }

    livro->ano = -1;
    livro->autor = NULL;
    livro->titulo = NULL;

    return livro;
}

void LerLivro(tLivros* livro) {
    char letra = '\n';
    int indice = 0;
    //limpeza do buffer
    scanf("%*[^a-zA-Z]");

    livro->autor = (char*) malloc (5*sizeof(char));
    livro->titulo = (char*) malloc (5*sizeof(char));

    //leitura dinamica do autor
    while (letra != '\0') {
        scanf("%c", &letra);
        //colocando um '\0' quando ler um '\n'
        if(letra == '\n') letra = '\0';

        if(indice >= sizeof(*(livro->autor))) {
            livro->titulo = (char*) realloc (livro->titulo, 2 * indice * sizeof(char));
        }
        livro->titulo[indice] = letra; 
        indice++;
    }

    //leitura dinamica do titulo
    indice = 0;
    letra = '\n';
    while (letra != '\0') {
        scanf("%c", &letra);
        //colocando um '\0' quando ler um '\n'
        if(letra == '\n') letra = '\0';

        if(indice >= sizeof(*(livro->autor))) {
            livro->autor = (char*) realloc (livro->autor, 2 * indice * sizeof(char));
        }
        livro->autor[indice] = letra; 
        indice++;
    }
    
    scanf("%d", &livro->ano);
}

void ImprimeLivro(tLivros* livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n\n", livro->ano);
}

char *getTitulo(tLivros* livro) {
    return livro->titulo;
}

void ApagaLivro(tLivros* livro) {
    if(livro != NULL) {
        if(livro->titulo != NULL) free(livro->titulo);

        if(livro->autor != NULL) free(livro->autor);

        free(livro);
    }
}