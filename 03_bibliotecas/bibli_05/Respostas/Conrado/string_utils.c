#include "string_utils.h"
#include <stdio.h>

int string_length(char *str) {
    int count = 0, i = 0;

    while(str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

void string_copy(char *src, char *dest) {
    int i = 0;

    while(src[i] == '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void string_upper(char *str) {
    int i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('Z' - 'A');
        }
    }
}

void string_lower(char *str) {
    int i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('Z' - 'A');
        }
    }
}

void string_reverse(char *str) {
    char str_aux[1001];
    int i = 0, tam;

    tam = string_length(str);

    while(str[i] != '\0') {
        str_aux[i] = str[tam - i];
    }
    str_aux[tam+1] = '\0';

    string_copy(str_aux, str);
}