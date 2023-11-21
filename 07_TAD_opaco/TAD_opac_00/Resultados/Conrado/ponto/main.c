#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    float centro_c_x, centro_c_y, raio_c, p_x, p_y;
    scanf("%f %f %f %f %f", &centro_c_x, &centro_c_y, &raio_c, &p_x, &p_y);

    tCirculo c = Circulo_Cria(centro_c_x, centro_c_y, raio_c);
    tPonto p = Pto_Cria(p_x, p_y);

    printf("%d", Circulo_Interior(c, p));

    Circulo_Apaga(c);
    Pto_Apaga(p);

    return 0;
}