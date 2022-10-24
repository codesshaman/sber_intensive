#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void srt(int *a, int n);
void output(int *a, int n);

int main() {
    int n = NMAX, data[NMAX];
    if (input(data, n) == 0) {
        srt(data, n);
        output(data, n);
        } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1)
        return -1;
    }
    return 0;
}

void srt(int *a, int n) {
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n - p - 1; i++) {
            if (a[i] > a[i+1]) {
                int swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        }
        printf("\n");
}
