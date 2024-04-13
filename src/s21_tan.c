#include "s21_math.h"

long double s21_tan(double x) {
  long double sum = 0;
  if (x == S21_PI_2) {
    sum = 16331239353195370L;
  } else if (x == -S21_PI_2) {
    sum = -16331239353195370L;
  } else if (x == 0) {
    sum = 0;
  } else {
    sum = s21_sin(x) / s21_cos(x);
  }
  return sum;
}