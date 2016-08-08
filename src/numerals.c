#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "numerals.h"

void add(char *first, char *second, char *buf) {
    integerToNumeral(numeralToInteger(first) + numeralToInteger(second), buf);
}

void subtract(char *first, char *second, char *buf) {
    integerToNumeral(numeralToInteger(first) - numeralToInteger(second), buf);
}

int numeralToInteger(char *numeral) {
    int i, len = strlen(numeral);
    int totalForNumeral = 0;
    char thisChar[] = " ";
    char *numeralPtr = numeral + len -1;
    int thisVal;
    int prevVal = 0;

    for (i = len; i > 0; i--) {
        memcpy(thisChar, numeralPtr--, sizeof(int));
        thisVal = charToInteger(thisChar);
        if (thisVal < prevVal) {
            totalForNumeral -= thisVal;
        }
        else {
            totalForNumeral += thisVal;
        }
        prevVal = thisVal;
    }
    return totalForNumeral;
}

void integerToNumeral(int number, char *buf) {
    char numerals[13][3] = { "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i" };
    char *numeralsPtr = numerals[0];
    char numeral[3];
    strcpy(numeral, numeralsPtr);
    numeralsPtr += 3;

    while (number > 0) {
        while (number < numeralToInteger(numeral)) {
            strcpy(numeral, numeralsPtr);
            numeralsPtr += 3;
        }
        while (number >= numeralToInteger(numeral)) {
            strcat(buf, numeral);
            number -= numeralToInteger(numeral);
        }
    }
}

int charToInteger(char *c) {
    switch(*c) {
        case 'i':
            return 1;
        case 'v':
            return 5;
        case 'x':
            return 10;
        case 'l':
            return 50;
        case 'c':
            return 100;
        case 'd':
            return 500;
        case 'm':
            return 1000;
        default:
            printf("The letter %s is not a valid Roman numeral!\n", c);
            exit(1);
    }
}
