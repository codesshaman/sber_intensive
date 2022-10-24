#include <stdio.h>
#define NMAX 10
int input(int *a, int *z, int n);
void output(int *a, int n);
void arr_result(int *a, int r, int n);

int main() {
    int n = NMAX, z, data[NMAX];
    if (input(data, z, n) == 0) {
        squaring(data, &n);
        output(data, &n);
        } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int n) {
    int prov = scanf("%d", z);
    if (prov != 1 || *z > NMAX || *z <= 0) {
        return -1;
    }
    for (int *p = a; p - a < *z; p++) {
        if (scanf("%d", p) != 1) {
        return -1;
    }
    scanf("%d", &n);
}
    return n;
}

void arr_result(int *a, int z, int n) {
    for (int s = 0; s < n, s++) {
    int k = a[0];
    for (int = 0; i < z - 1; i++) {
        a[i] = a[i + 1];
    }
        a [z - 1] = k;
    }
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
        }
        printf("\n");
}
