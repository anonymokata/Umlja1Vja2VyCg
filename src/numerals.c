#include <string.h>
#include "numerals.h"

void add(char *first, char *second, char *buf) {
    strcpy(buf, first);
    strcat(buf, second);
}

int numeralToNumericValue(char *numeral) {
    int i;
    int len = strlen(numeral);
    int totalForNumeral = 0;
    for (i = len - 1; i >= 0; i--) {
        char *c = numeral;
        int valueForNumeral = charToDigit(c);
        totalForNumeral += valueForNumeral;
    }
    return totalForNumeral;
}

int charToDigit(char *c) {
    switch(*c) {
        case 'i':
            return 1;
        default:
            return 0;
    }
}
