#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1E-6

int normalization(double *data, int n);
int input(double *data, int n);
void output(double *data, int n);
void sarri(int *n, int* err);
double max(double *data, int n);
double min(double *data, int n);
double mean(double *data, int n);
double variance(double *data, int n);

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

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if(fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }
    return result;
}

double max(double *data, int n) {
  double x = data [0];
  for (int i = 1; i < n; i++) {
    if (data[i] > x)
      x = data[i];
  }
  return x;
}
double min(double *data, int n) {
  double x = data [0];
  for (int i = 1; i < n; i++) {
    if (data[i] < x)
      x = data[i];
  }
  return x;
}

double mean(double *data, int n) {
double rs;
double c = 0.0;
for (int i = 0; i < n; i++) {
c += data[i];
}
rs = c / n;
return rs;
}

double variance(double *data, int n) {
    double buf = mean(data, n);
    double init = 0.0;
    for (int i = 0; i < n; i++) {
      init += (data[i] - buf) * (data[i] - buf);
    }
    init /= n;
    return init;
}

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
