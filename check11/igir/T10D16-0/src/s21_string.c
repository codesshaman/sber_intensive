#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"
//#include <string.h>

unsigned s21_strlen(const char *str) {
    unsigned length = 0;
    for(;*(str+length);length++);
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    for (;*str1 && *str1 == *str2; str1++, str2++);
    return *str1 - *str2;
}

int s21_strcpy(char *str2, const char *str1) {
    int ret = 0;
    for(unsigned i = 0; (i < s21_strlen(str1)) && (str1[i+1] != '\0'); i++)
        str2[i] = str1[i];
    if (s21_strlen(str2) < s21_strlen(str1) || str1 == NULL)
        ret = 1;
    return ret;
}
