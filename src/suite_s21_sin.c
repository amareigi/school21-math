#include "math_suitecases.h"

START_TEST(sin_1) {
  double number = 0;
  ck_assert_float_eq(s21_sin(number), sin(number));
}
END_TEST

START_TEST(sin_2) {
  double number = 1.0;
  ck_assert_float_eq_tol(sin(number), s21_sin(number), 1e-6);
}
END_TEST

START_TEST(sin_3) {
  double number = -1.0;
  ck_assert_float_eq_tol(sin(number), s21_sin(number), 1e-6);
}
END_TEST

START_TEST(sin_4) {
  double number = 0.999999;
  ck_assert_float_eq_tol(sin(number), s21_sin(number), 1e-6);
}
END_TEST

START_TEST(sin_5) {
  double number = -0.999999;
  ck_assert_float_eq_tol(sin(number), s21_sin(number), 1e-6);
}
END_TEST

START_TEST(sin_6) {
  int success = 0;
  long double math = sin(NAN), s21_math = s21_sin(NAN);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(sin_7) {
  int success = 0;
  long double math = sin(INFINITY), s21_math = s21_sin(INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(sin_8) {
  int success = 0;
  long double math = sin(-INFINITY), s21_math = s21_sin(-INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(sin_9) {
  double number = S21_PI_4;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_10) {
  double number = -S21_PI_4;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  double number = S21_PI_2;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_12) {
  double number = -S21_PI_2;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_13) {
  double number = S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_14) {
  double number = -S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_15) {
  double number = 2 * S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_16) {
  double number = -2 * S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_17) {
  double number = -5 * S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

START_TEST(sin_18) {
  double number = 5 * S21_PI;
  ck_assert_double_eq_tol(s21_sin(number), sin(number), 1e-06);
}
END_TEST

Suite *suite_s21_sin(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_sin");
  tc13 = tcase_create("case_sin");

  tcase_add_test(tc13, sin_1);
  tcase_add_test(tc13, sin_2);
  tcase_add_test(tc13, sin_3);
  tcase_add_test(tc13, sin_4);
  tcase_add_test(tc13, sin_5);
  tcase_add_test(tc13, sin_6);
  tcase_add_test(tc13, sin_7);
  tcase_add_test(tc13, sin_8);
  tcase_add_test(tc13, sin_9);
  tcase_add_test(tc13, sin_10);
  tcase_add_test(tc13, sin_11);
  tcase_add_test(tc13, sin_12);
  tcase_add_test(tc13, sin_13);
  tcase_add_test(tc13, sin_14);
  tcase_add_test(tc13, sin_15);
  tcase_add_test(tc13, sin_16);
  tcase_add_test(tc13, sin_17);
  tcase_add_test(tc13, sin_18);

  suite_add_tcase(s13, tc13);
  return s13;
}
