#include "s21_math.h"

long double s21_fabs(double x) {
  if (x != x) return S21_NAN;
  if (x == S21_INF) return x;
  if (x == S21_NINF) return -x;
  return x < 0 ? -x : x;
}
