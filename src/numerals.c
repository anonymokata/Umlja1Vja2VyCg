#include <string.h>
#include "numerals.h"

void add(char *first, char *second, char *str) {
    strcpy(str, first);
    strcat(str, second);
}

int numeralToNumericValue(char *str) {
    int i;
    int len = strlen(str);
    int totalForNumeral = 0;
    for (i = len - 1; i >= 0; i--) {
        char *c = str;
        int valueForNumeral = charToNumericValue(c);
        totalForNumeral += valueForNumeral;
    }
    return totalForNumeral;
}

int charToNumericValue(char *c) {
    switch(*c) {
        case 'i':
            return 1;
        default:
            return 0;
    }
}
