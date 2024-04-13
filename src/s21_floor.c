#include "s21_math.h"

long double s21_floor(double x) {
  if (x != x) {
    return x;
  }
  if (x == S21_INF || x == S21_NINF) {
    return x;
  }
  double floor_x = 0;
  floor_x = (long long int)x;
  if (s21_fabs(x - floor_x) > 0.) {
    if (x < 0.) {
      floor_x -= 1;
    }
  }
  return floor_x;
}
