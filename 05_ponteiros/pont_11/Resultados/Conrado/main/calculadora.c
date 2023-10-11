#include "calculadora.h"

float Calcular(float num1, float num2, CalculatoraCallback operacao) {
    float resultado = 0;

    resultado = operacao(num1, num2);

    return resultado;
}