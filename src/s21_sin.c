#include "s21_math.h"

long double s21_sin(double x) {
  long double sum_sin = 0;
  long double new = 0;
  new = x;
  int i = 0;
  if (x != x || x == S21_NINF || x == S21_INF) {
    return S21_NAN;
  }
  if (x == 0) {
    sum_sin = 0;
  } else {
    for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
      if (x > 2 * S21_PI) {
        x -= 2 * S21_PI;
      } else {
        x += 2 * S21_PI;
      }
    }
    long double sign = 1.0;
    if (x < 0) {
      x = -x;
      sign = -1.0;
    }
    while ((new > S21_EPS) || (new < -S21_EPS)) {
      new = s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_fact(2 * i + 1);
      sum_sin += new;
      i++;
    }
    sum_sin = sum_sin * sign;
  }
  return sum_sin;
}
