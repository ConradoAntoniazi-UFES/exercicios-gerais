#include "string_utils.h"
#include <stdio.h>

void printMenu() {
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida\n");
}

int main() {
    char str[1001];
    int acao;

    scanf("%[^\n]", str);

    printMenu();

    while (scanf("%d", acao) != 6){
        if(acao == 1){
            
        }
        else if(acao == 2){
            
        }
        else if(acao == 3){
            
        }
        else if(acao == 4){
            
        }
        else if(acao == 5){
            
        }
        else if(acao == 6){
            break;
        }
    }

    return 0;
}