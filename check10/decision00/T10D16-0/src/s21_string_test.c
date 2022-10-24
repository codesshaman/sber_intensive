#include <stdlib.h>
#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test(const char *str, int n);
void s21_strcmp_test(char *str1, char *str2);
void s21_strcpy_test(char *dest, char *src);

int main() {
#ifdef LEN
    s21_strlen_test("758", 3);
    s21_strlen_test("Школа", 10);
    s21_strlen_test(" ", 1);
    s21_strlen_test("Shoes", 5);
#endif

#ifdef CMP
    s21_strcmp_test("ONE", "ONE");
    s21_strcmp_test("малыш", "малыш");
    s21_strcmp_test("569", "569");
    s21_strcmp_test("", "");
#endif

#ifdef CPY
    char test[4] = "tes";
    char test2[4] = "bab";
    s21_strcpy_test(test, test2);
    char test3[6] = "ну";
    char test4[6] = "му";
    s21_strcpy_test(test3, test4);
    char test5[7] = "123456";
    char test6[7] = "789125";
    s21_strcpy_test(test5, test6);
#endif
    return 0;
}
void s21_strlen_test(const char *str, int n) {
    if (s21_strlen(str) == n) {
        printf("%s %d SUCCESS\n", str, n);
} else {
printf("%s %d FAIL\n", str, n);
}
}

void s21_strcmp_test(char *str1, char *str2) {
    if (s21_strcmp(str1, str2) == 0) {
                printf("%s %s SUCCESS\n", str1, str2);
} else {
        printf("%s %s FAIL\n", str1, str2);
}
}

void s21_strcpy_test(char *dest, char *str) {
    s21_strcpy(dest, str);
    int m = s21_strcmp(dest, str);
    if (m == 0) {
        printf("%s %s SUCCESS\n", dest, str);
        } else {
        printf("%s %s FAIL\n", dest, str);
    }
}
