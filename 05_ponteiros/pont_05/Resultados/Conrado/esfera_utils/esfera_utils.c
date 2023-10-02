#include "esfera_utils.h"

void CalculaVolume (float R, float *volume) {
    *volume = (float)4 / 3 * PI * R * R * R;
}

void CalculaArea (float R, float *area) {
    *area = 4 * PI * R * R;
}