#include "calculadora.h"
#include <stdio.h>

float Adicao (float a, float b) {
    return a + b;
}

float Subtracao (float a, float b) {
    return a - b;
}

float Multiplicacao (float a, float b) {
    return a * b;
}

float Divisao (float a, float b) {
    return a / b;
}

int main () {
    char acao = '\0';
    float resultado = 0, num1 = 0, num2 = 0;

    while (acao != 'f') {
        
        scanf("%*[^asmdf]");
        scanf("%c\n", &acao);
        scanf("%f %f\n", &num1, &num2);

        if(acao == 'a') {
            resultado = Calcular(num1, num2, Adicao);
            printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);

        } else if(acao == 's') {
            resultado = Calcular(num1, num2, Subtracao);
            printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);

        } else if(acao == 'm') {
            resultado = Calcular(num1, num2, Multiplicacao);
            printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);

        } else if(acao == 'd') {
            resultado = Calcular(num1, num2, Divisao);
            printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);

        }
    }

    return 0;
}