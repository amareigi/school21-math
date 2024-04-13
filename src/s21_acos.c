#include "s21_math.h"

long double s21_acos(double x) {
  long double number = 0;
  if (x == 1)
    number = 0;
  else if (x == -1)
    number = S21_PI;
  else if (x == 0)
    number = S21_PI / 2;
  else if (0 < x && x < 1)
    number = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (-1 < x && x < 0)
    number = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  else
    number = S21_NAN;

  return number;
}
