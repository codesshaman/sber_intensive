#include "data_stat.h"

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
