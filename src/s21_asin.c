#include "s21_math.h"

long double s21_asin(double x) {
  long double number = 0;
  if (x == 1)
    number = S21_PI / 2;
  else if (x == -1)
    number = -S21_PI / 2;
  else if (s21_fabs(x) < S21_EPS)
    number = 0;
  else if (-1 < x && x < 1)
    number = s21_atan(x / s21_sqrt(1 - x * x));
  else
    return S21_NAN;
  return number;
}
