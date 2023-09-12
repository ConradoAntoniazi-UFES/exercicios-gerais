#include "string_utils.h"
#include <stdio.h>

void printMenu() {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

int main() {
    char str[1001];
    int acao;

    scanf("%[^\n]", str);

    printMenu();

    while (scanf("%d", &acao) == 1){

        if(acao == 1){
            int tam = string_length(str);
            printf("Tamanho da string: %d\n\n", tam);
            printMenu();
        }
        else if(acao == 2){
            char str_cpy[1001];
            string_copy(str, str_cpy);
            printf("String copiada: %s\n\n", str_cpy);
            printMenu();
        }
        else if(acao == 3){
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n", str);
            printMenu();
        }
        else if(acao == 4){
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n", str);
            printMenu();
        }
        else if(acao == 5){
            string_reverse(str);
            printf("String invertida: \n%s\n\n", str);
            printMenu();
        }
        else if(acao == 6){
            break;
        }
    }

    return 0;
}