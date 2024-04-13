#include "s21_math.h"

long double s21_cos(double x) {
  long double sum_cos = 0;
  int i = 0;
  if (x != x || x == S21_NINF || x == S21_INF) {
    return S21_NAN;
  }
  for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
    if (x > 2 * S21_PI) {
      x -= 2 * S21_PI;
    } else {
      x += 2 * S21_PI;
    }
  }
  if (x == 0) {
    sum_cos = 1;
  } else if (x < 0) {
    x = -x;
  }
  long double new = 0;
  new = x;
  while ((new > S21_EPS) || (new < -S21_EPS)) {
    new = s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_fact(2 * i);
    sum_cos += new;
    i++;
  }
  return sum_cos;
}
