#include "data_io.h"
#include <stdio.h>

int input(double *data, int n) {
    int err = 0;
    if ((!scanf("%d", &n)) || n < 1) {
        err = 1;
    } else {
        err = 0;
    }
    for (double p = *data; p - *data < n; p++) {
        scanf("%lf", &p);
    }
    return err;
}
void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf ("%.2lf ", data[i]);
        } else {
            printf("%.2lf", data[i]);
        }
    }
}

void sarri(int *n, int *err) {
    if (!(scanf("%d", n) == 1 && *n < 1)) {
        *err = 0;
    } else {
        *err = 1;
    }
}
