#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <ctype.h>
#include <float.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 0.000000001
#define S21_PI_2 1.57079632679489661923
#define S21_PI_4 0.78539816339744830962
#define S21_INF (1.0 / 0.0)
#define S21_NINF (-1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)

#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

// dop
#define S21_POS_INF +1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INT(x) (x == (int)x)
#define S21_IS_POS_INF(x) (x == S21_POS_INF)
#define S21_IS_NEG_INF(x) (x == S21_NEG_INF)

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_log(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_fact(int N);
long double s21_pow(double base, double ex);

#endif
