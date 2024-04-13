#include "s21_math.h"

long double s21_atan(double x) {
  long double summ = 0;
  if (x != x) {
    return S21_NAN;
  }
  if (x == 1)
    summ = S21_PI / 4;
  else if (x == -1)
    summ = -S21_PI / 4;
  else if (x == S21_INF)
    summ = S21_PI / 2;
  else if (x == S21_NINF)
    summ = -S21_PI / 2;

  else if (x < 1 && x > -1) {
    int n = 1;
    long double term = 0;
    term = x;
    while ((s21_fabs(term) > 1e-9)) {
      summ += term;
      n++;
      term = -term * x * x * (2 * n - 3) / (2 * n - 1);
    }
  } else {
    int i = -1;
    while (++i < 1000) {
      summ += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    summ = S21_PI * s21_sqrt(x * x) / (2 * x) - summ;
  }
  return summ;
}
