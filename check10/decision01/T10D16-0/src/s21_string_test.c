#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_strlen_test();
int check_strlen(const char *str);

int main() {
    #ifdef LEN
    s21_strlen_test();
    #endif
    return 0;
}

int s21_strlen_test() {
    char *test_str[] = {"TENLETTERS", "ASDQWE", "MORETHENTENLETTERS"};
    int res[] = {1, 0, 0};
    for (int i = 0; i < 3; i++) {
        printf("%s\n", test_str[i]);
        printf("%d", res[i]);
        if (res[i] == check_strlen(*(test_str + i))) {
            printf("SUCCESS\n");
        } else {
           printf("FAIL\n");
        }
    }
    return 0;
}

int check_strlen(const char *str) {
    int res = 0;
    if (str == NULL || str == '\0') {
        res = -1;
    }
    if (s21_strlen(str) == 10)
        res = 1;
    return res;
}
