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
    if(mes == 1) printf("Janeiro");
    else if(mes == 2) printf("Fevereiro");
    else if(mes == 3) printf("Marco");
    else if(mes == 4) printf("Abril");
    else if(mes == 5) printf("Maio");
    else if(mes == 6) printf("Junho");
    else if(mes == 7) printf("Julho");
    else if(mes == 8) printf("Agosto");
    else if(mes == 9) printf("Setembro");
    else if(mes == 10) printf("Outubro");
    else if(mes == 11) printf("Novembro");
    else if(mes == 12) printf("Dezembro");
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int numeroDiasMes(int mes, int ano) {
    if(verificaBissexto(ano) && mes == 2) return 29;
    else if(!verificaBissexto(ano) && mes == 2) return 28;
    else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes ==12) return 31;
    else return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(dia1 == dia2 && mes1 == mes2 && ano1 == ano2) return 0;

    else if(ano1 > ano2) return 1;
    else if(ano1 == ano2 && mes1 > mes2) return 1;
    else if(ano1 == ano2 && mes1 == mes2 && dia1 > dia2) return 1;

    else if(ano1 < ano2) return -1;
    else if(ano1 == ano2 && mes1 < mes2) return -1;
    else if(ano1 == ano2 && mes1 == mes2 && dia1 < dia2) return -1;
}

int calculaDiasAteMes(int mes, int ano) {
    int i, soma_dias = 0;

    for(i = 1; i < mes; i++) {
        soma_dias += numeroDiasMes(i, ano);
    }

    return soma_dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int i, c, diferencaDias = 0;
    int dia_aux, mes_aux, ano_aux;

    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        dia_aux = dia1;
        mes_aux = mes1;
        ano_aux = ano1;
        dia1 = dia2;
        mes1 = mes2;
        ano1 = ano2;
        dia2 = dia_aux;
        mes2 = mes_aux;
        ano2 = ano_aux;
    }

    for(i = ano1; i <= ano2; i++) {
        if(ano1 == ano2) {
            for(c = mes1; c <= mes2; c++) {
                if(mes1 == mes2){
                    diferencaDias += dia2 - dia1;
                }
                else if(c == mes1 && i == ano1) {
                    diferencaDias += numeroDiasMes(mes1, ano1) - dia1;
                }
                else if(c == mes2 && i == ano2) {
                    diferencaDias += dia2;
                }
                else{
                    diferencaDias += numeroDiasMes(c, i);
                }
            }
        }
        else if (i == ano1) {
            if(verificaBissexto(ano1)) diferencaDias += 366 - (calculaDiasAteMes(mes1, ano1) + dia1);
            else diferencaDias += 365 - (calculaDiasAteMes(mes1, ano1) + dia1);
        }
        else if (i == ano2) {
            diferencaDias += calculaDiasAteMes(mes2, ano2) + dia2;
        }
        else{
            if(verificaBissexto(i)) diferencaDias += 366;
            else diferencaDias += 365;
        }
    }

    return diferencaDias;
}