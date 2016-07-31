#include <string.h>
#include "numerals.h"

void add(char *first, char *second, char *str) {
    strcpy(str, first);
    strcat(str, second);
}
