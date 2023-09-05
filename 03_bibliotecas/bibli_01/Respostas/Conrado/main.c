#include "esfera_utils.h"
#include <stdio.h>

int main () {
    float raio = 0.0, volume = 0.0, area = 0.0;

    scanf("%f", &raio);

    area = calcula_area(raio);
    volume = calcula_volume(raio);

    printf("Area: %.02f\nVolume: %.02f\n", area, volume);

    return 0;
}