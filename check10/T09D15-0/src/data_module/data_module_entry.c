#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_process.h"
#include "../data_libs/data_io.h"

int main() {
    double *data = NULL;
    int n, err = 0;
    sarri(&n, &err);

    if (err == 0) {
        data = calloc(n, sizeof(double));
        input(data, n);
    } //Don`t forget to allocate memory !
    if (err == 0 && normalization(data, n)) {
        input(data, n);
    } else {
        printf("Error");
    }
    free(data);
    return 0;
}
