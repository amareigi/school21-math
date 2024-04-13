#include "s21_math.h"

long double s21_pow(double base, double ex) {
  long double res = 0;
  if (ex == 0 || base == 1 || (base == -1 && (is_inf(ex)))) {
    res = 1;
  } else if (((base < 0 && base != S21_NINF) &&
              ((int)ex - ex != 0 && !is_inf(ex))) ||
             is_nan(ex)) {
    res = S21_NAN;
  } else if ((base == S21_INF && ex > 0) ||
             (base == S21_NINF &&
              ((ex > 0 && (int)ex % 2 == 0) || ex == S21_INF)) ||
             (s21_fabs(base) < 1 && ex == S21_NINF) ||
             (s21_fabs(base) > 1 && ex == S21_INF) ||
             (base == 0 && ex == S21_NINF) || (base == DBL_MIN && ex < 0)) {
    res = S21_INF;
  } else if ((base == S21_INF && ex < 0) ||
             (base == S21_NINF && (ex < 0 && (int)ex % 2 == 0)) ||
             ((base == 0 || base == DBL_MIN) && ex > 0) ||
             (s21_fabs(base) > 1 && ex == S21_NINF) ||
             (s21_fabs(base) < 1 && ex == S21_INF) ||
             (base == -S21_EXP && (ex > 0 && (int)ex % 2 == 0))) {
    res = 0;
  } else if ((base == -S21_EXP && (ex > 0 && (int)ex % 2 != 0)) ||
             (base == S21_NINF && (ex < 0 && (int)ex % 2 != 0))) {
    res = -S21_EXP;
  } else if (base < 0) {
    base = -base;
    res = s21_exp(ex * s21_log(base));
    if (s21_fmod(ex, 2) != 0) res = -res;
  } else {
    res = s21_exp(ex * s21_log(base));
  }
  return res;
}
