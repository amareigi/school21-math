#include "math_suitecases.h"

START_TEST(cos_1) {
  double number = 0;
  ck_assert_float_eq(s21_cos(number), cos(number));
}
END_TEST

START_TEST(cos_2) {
  double number = 1.0;
  ck_assert_float_eq_tol(cos(number), s21_cos(number), 1e-6);
}
END_TEST

START_TEST(cos_3) {
  double number = -1.0;
  ck_assert_float_eq_tol(cos(number), s21_cos(number), 1e-6);
}
END_TEST

START_TEST(cos_4) {
  double number = 0.999999;
  ck_assert_float_eq_tol(cos(number), s21_cos(number), 1e-6);
}
END_TEST

START_TEST(cos_5) {
  double number = -0.999999;
  ck_assert_float_eq_tol(cos(number), s21_cos(number), 1e-6);
}
END_TEST

START_TEST(cos_6) {
  int success = 0;
  long double math = cos(NAN), s21_math = s21_cos(NAN);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(cos_7) {
  int success = 0;
  long double math = cos(INFINITY), s21_math = s21_cos(INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(cos_8) {
  int success = 0;
  long double math = cos(-INFINITY), s21_math = s21_cos(-INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(cos_9) {
  double number = S21_PI_4;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_10) {
  double number = -S21_PI_4;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_11) {
  double number = S21_PI_2;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_12) {
  double number = -S21_PI_2;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_13) {
  double number = S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_14) {
  double number = -S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_15) {
  double number = 2 * S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_16) {
  double number = -2 * S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_17) {
  double number = -5 * S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_18) {
  double number = 5 * S21_PI;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

START_TEST(cos_19) {
  double number = 3 * S21_PI_2;
  ck_assert_double_eq_tol(s21_cos(number), cos(number), 1e-06);
}
END_TEST

Suite *suite_s21_cos(void) {
  Suite *s6;
  TCase *tc6;
  s6 = suite_create("s21_cos");
  tc6 = tcase_create("case_cos");

  tcase_add_test(tc6, cos_1);
  tcase_add_test(tc6, cos_2);
  tcase_add_test(tc6, cos_3);
  tcase_add_test(tc6, cos_4);
  tcase_add_test(tc6, cos_5);
  tcase_add_test(tc6, cos_6);
  tcase_add_test(tc6, cos_7);
  tcase_add_test(tc6, cos_8);
  tcase_add_test(tc6, cos_9);
  tcase_add_test(tc6, cos_10);
  tcase_add_test(tc6, cos_11);
  tcase_add_test(tc6, cos_12);
  tcase_add_test(tc6, cos_13);
  tcase_add_test(tc6, cos_14);
  tcase_add_test(tc6, cos_15);
  tcase_add_test(tc6, cos_16);
  tcase_add_test(tc6, cos_17);
  tcase_add_test(tc6, cos_18);
  tcase_add_test(tc6, cos_19);

  suite_add_tcase(s6, tc6);
  return s6;
}
