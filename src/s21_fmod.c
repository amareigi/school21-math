#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double s21_res = 0.0;
  if ((x == S21_INF || x == S21_NINF) || (y != y)) {
    return S21_NAN;
  }
  if (y == S21_INF || y == S21_NINF) {
    return x;
  }
  if (s21_fabs(y) < 0.0000001) {
    return S21_NAN;
  }
  if (s21_fabs(x) < 0.0000001) {
    s21_res = 0;
  } else {
    long long int int_div = 0;
    int_div = x / y;
    s21_res = (long double)x - int_div * (long double)y;
  }
  return s21_res;
}
