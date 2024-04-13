#include "math_suitecases.h"

START_TEST(tan_1) {
  double number = 0;
  ck_assert_float_eq(s21_tan(number), tan(number));
}
END_TEST

START_TEST(tan_2) {
  double number = 1.0;
  ck_assert_float_eq_tol(tan(number), s21_tan(number), 1e-6);
}
END_TEST

START_TEST(tan_3) {
  double number = -1.0;
  ck_assert_float_eq_tol(tan(number), s21_tan(number), 1e-6);
}
END_TEST

START_TEST(tan_4) {
  double number = 0.999999;
  ck_assert_float_eq_tol(tan(number), s21_tan(number), 1e-6);
}
END_TEST

START_TEST(tan_5) {
  double number = -0.999999;
  ck_assert_float_eq_tol(tan(number), s21_tan(number), 1e-6);
}
END_TEST

START_TEST(tan_6) {
  int success = 0;
  long double math = tan(NAN), s21_math = s21_tan(NAN);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(tan_7) {
  int success = 0;
  long double math = tan(INFINITY), s21_math = s21_tan(INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(tan_8) {
  int success = 0;
  long double math = tan(-INFINITY), s21_math = s21_tan(-INFINITY);
  if (isnan(math) && isnan(s21_math)) success++;
  ck_assert_int_eq(1, success);
}
END_TEST

START_TEST(tan_9) {
  double number = S21_PI_4;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_10) {
  double number = -S21_PI_4;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_11) {
  double number = S21_PI_2;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_12) {
  double number = -S21_PI_2;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_13) {
  double number = S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_14) {
  double number = -S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_15) {
  double number = 2 * S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_16) {
  double number = -2 * S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_17) {
  double number = -5 * S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

START_TEST(tan_18) {
  double number = 5 * S21_PI;
  ck_assert_double_eq_tol(s21_tan(number), tan(number), 1e-06);
}
END_TEST

Suite *suite_s21_tan(void) {
  Suite *s15;
  TCase *tc15;
  s15 = suite_create("s21_tan");
  tc15 = tcase_create("case_tan");

  tcase_add_test(tc15, tan_1);
  tcase_add_test(tc15, tan_2);
  tcase_add_test(tc15, tan_3);
  tcase_add_test(tc15, tan_4);
  tcase_add_test(tc15, tan_5);
  tcase_add_test(tc15, tan_6);
  tcase_add_test(tc15, tan_7);
  tcase_add_test(tc15, tan_8);
  tcase_add_test(tc15, tan_9);
  tcase_add_test(tc15, tan_10);
  tcase_add_test(tc15, tan_11);
  tcase_add_test(tc15, tan_12);
  tcase_add_test(tc15, tan_13);
  tcase_add_test(tc15, tan_14);
  tcase_add_test(tc15, tan_15);
  tcase_add_test(tc15, tan_16);
  tcase_add_test(tc15, tan_17);
  tcase_add_test(tc15, tan_18);

  suite_add_tcase(s15, tc15);
  return s15;
}
