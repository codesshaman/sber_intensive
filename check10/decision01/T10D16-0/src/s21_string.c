#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_strlen(const char *str) {
        int l = 0;
        for (; *(str + l); l++) {}
        return l;
}
