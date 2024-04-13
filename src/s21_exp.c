#include "s21_math.h"

long double s21_exp(double x) {
  double add_value = 1;
  long double series = 1;
  long double i = 1;
  int negative = 0;
  if (x < 0) {
    x *= -1;
    negative = 1;
  }
  while (s21_fabs(add_value) > S21_EPS) {
    add_value *= x / i;
    i += 1;
    series += add_value;
    if (series > DBL_MAX) {
      series = S21_INF;
      break;
    }
  }
  if (negative == 1) {
    if (series > DBL_MAX) {
      series = 0;
    } else {
      series = 1. / series;
    }
  }
  return series;
}
