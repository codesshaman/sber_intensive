#include "s21_string.h"
#include <stdio.h>

int main () {
    char *test = NULL;
    char test_1[] = {"1234567890"};
    char test_2[] = {"Hello world!"};
    char test_3[] = {"- Hello world! -"};
    s21_strlen_test(test_1[]);
    s21_strlen_test(test_2[]);
    s21_strlen_test(test_3[]);
    printf("SUCCESS)");
    return 0;
}

int s21_strlen_test(char *test) {
    char *test = NULL;
    printf("%c", test);
    return 0;
}