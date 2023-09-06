#include "data.h"
#include <stdio.h>

int verificaBissexto(int ano) {
    if(ano % 4 == 0 && ano % 100 != 0) return 1;
    else if(ano % 100 == 0 && ano % 400 == 0) return 1;

    return 0;
}

int verificaDataValida(int dia, int mes, int ano) {
    if(verificaBissexto(ano) && mes == 2 && (dia > 0 && dia <= 29)) return 1;
    else if(!verificaBissexto(ano) && mes == 2 && (dia > 0 && dia <= 28)) return 1;
    else if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12) && (dia > 0 && dia <= 31) && ano >= 0) return 1;
    else if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 0 && dia <= 30) && ano >= 0) return 1;

    return 0;
}

void imprimeMesExtenso(int mes) {
    if(mes == 1) printf("janeiro");
    else if(mes == 2) printf("fevereiro");
    else if(mes == 3) printf("marco");
    else if(mes == 4) printf("abril");
    else if(mes == 5) printf("maio");
    else if(mes == 6) printf("junho");
    else if(mes == 7) printf("julho");
    else if(mes == 8) printf("agosto");
    else if(mes == 9) printf("setembro");
    else if(mes == 10) printf("outubro");
    else if(mes == 11) printf("novembro");
    else if(mes == 12) printf("dezembro");
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int numeroDiasMes(int mes, int ano) {
    if(verificaBissexto(ano) && mes == 2) return 29;
    else if(!verificaBissexto(ano) && mes == 2) return 28;
    else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12) return 31;
    else return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(dia1 == dia2 && mes1 == mes2 && ano1 == ano2) return 0;
    else if(dia1 > 1);
}