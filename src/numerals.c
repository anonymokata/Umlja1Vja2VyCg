#include <string.h>
#include "numerals.h"

void add(char *first, char *second, char *str) {
    strcpy(str, first);
    strcat(str, second);
}

int charToValue(char *c) {
    switch(*c) {
        case 'i':
            return 1;
        default:
            return 0;
    }
}
