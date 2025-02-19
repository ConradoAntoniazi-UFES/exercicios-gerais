#include <stdio.h>
#include "matrix_utils.h"

void print_menu() {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

int main() {
    int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0, acao = 0, escalar = 0, selector = 0;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    print_menu();

    while (scanf("%d", &acao) == 1) {
        if(acao == 6) break;
        else if(acao == 1) {
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
                
            } else printf("Erro: as dimensoes da matriz nao correspondem\n");

        } else if(acao == 2) {
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);

            } else printf("Erro: as dimensoes da matriz nao correspondem\n");

        } else if(acao == 3) {
            if(possible_matrix_multiply(cols1, rows2)) {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);

            } else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");

        } else if(acao == 4) {
            scanf("%d", &escalar);
            scanf("%d", &selector);
            if(selector == 1) {
                scalar_multiply(rows1, cols1, matrix1, escalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else {
                scalar_multiply(rows2, cols2, matrix2, escalar);
                matrix_print(rows2, cols2, matrix2);
            }
        } else if(acao == 5) {
            int result1[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(cols1, rows1, result1);

            int result2[cols2][rows2];
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols2, rows2, result2);
        }
        
        print_menu();
    }
    
    return 0;
}