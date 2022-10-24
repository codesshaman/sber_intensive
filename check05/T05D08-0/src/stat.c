#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));
        } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int *n) {
    int prov = scanf("%d", n);
    if (prov != 1 || *n > NMAX || *n <= 0)
        return -1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1)
        return -1;
    }
    return 0;
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int *n) {
    int mx = a[0];
    for (int i = 0; i < *n; i++) {
        if (a[i] > mx)
        mx = a[i];
    }
    return mx;
}

int min(int *a, int *n) {
    int mn = a[0];
    for (int i = 0; i < *n; i++) {
        if (a[i] < mn)
        mn = a[i];
    }
    return mn;
}

double mean(int *a, int *n) {
double rs;
double c = 0;
for (int *p = a; p - a < *n; p++) {
c += *p;
}
rs = c / *n;
return rs;
}

double variance(int *a, int *n) {
    double buf = 0;
    double init = 0;
    for (int *p = a; p - a < *n; p++) {
        init += *p;
    }
    init /= *n;
    for (int *p = a; p - a < *n; p++) {
        buf += (*p-init) * (*p-init);
    }
    buf /= *n;
    return buf;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}
