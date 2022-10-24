#include <stdio.h>

int fibonacci(int N) {
  if (N == 1 || N == 2)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}
int main() {
  int N;
  char z;
  if (scanf("%d%c", &N, &z) == 2 && N > 0 && z == '\n') {
      printf("%d ", fibonacci(N));
  }
   else {
       printf ("n/a\n");
   } 
  return 0;
}
