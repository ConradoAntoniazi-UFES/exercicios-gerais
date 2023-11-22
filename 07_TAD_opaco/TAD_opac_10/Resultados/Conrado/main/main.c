#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimeListaOperacoes () {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");
}

int main () {
    int numAcoes = 0, acao, flag = 0;
    char titulo[50];
    tBiblioteca* biblioteca = InicializarBiblioteca();

    scanf("%d", &numAcoes);

    ImprimeListaOperacoes();

    for(int i = 0; i < numAcoes; i++) {
        scanf("%d", &acao);

        if(acao == 1) {
            tLivros* livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);

        } else if(acao == 2) {
            scanf("%*[^a-zA-Z]");
            scanf("%[^\n]", titulo);
            RemoverLivroDaBiblioteca(biblioteca, titulo);
        
        } else if(acao == 3) {
            ListarLivrosDaBiblioteca(biblioteca);
        } else {
            printf("Operacao invalida!\n");
            break;
        }
    }
    
    ApagaBiblioteca(biblioteca);
    return 1;   
}