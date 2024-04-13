#include "math_suitecases.h"

START_TEST(one) { ck_assert_float_eq(s21_atan(-15.01), atan(-15.01)); }
END_TEST

START_TEST(two) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(three) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(four) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), S21_EPS);
}
END_TEST

START_TEST(five) {
  double num = NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(six) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(seven) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), S21_EPS);
}
END_TEST

START_TEST(eight) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), S21_EPS);
}
END_TEST

START_TEST(nine) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), S21_EPS);
}
END_TEST

START_TEST(ten) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), S21_EPS);
}
END_TEST

START_TEST(eleven) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS); }
END_TEST

START_TEST(twelwe) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), S21_EPS);
}
END_TEST

START_TEST(thirteen) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS);
}
END_TEST

START_TEST(fourteen) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), S21_EPS);
}
END_TEST

START_TEST(fifteen) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), S21_EPS);
}
END_TEST

START_TEST(sixteen) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), S21_EPS);
}
END_TEST

START_TEST(seventeen) { ck_assert_float_nan(s21_atan(NAN)); }
END_TEST

START_TEST(eighteen) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI / 2), atan(S21_PI / 2), S21_EPS);
}
END_TEST

START_TEST(nineteen) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_PI / 2), atan(-S21_PI / 2), S21_EPS);
}
END_TEST

Suite *suite_s21_atan(void) {
  Suite *s4;
  TCase *tc4;
  s4 = suite_create("s21_atan");
  tc4 = tcase_create("case_atan");

  tcase_add_test(tc4, one);
  tcase_add_test(tc4, two);
  tcase_add_test(tc4, three);
  tcase_add_test(tc4, four);
  tcase_add_test(tc4, five);
  tcase_add_test(tc4, six);
  tcase_add_test(tc4, seven);
  tcase_add_test(tc4, eight);
  tcase_add_test(tc4, nine);
  tcase_add_test(tc4, ten);
  tcase_add_test(tc4, eleven);
  tcase_add_test(tc4, twelwe);
  tcase_add_test(tc4, thirteen);
  tcase_add_test(tc4, fourteen);
  tcase_add_test(tc4, fifteen);
  tcase_add_test(tc4, sixteen);
  tcase_add_test(tc4, seventeen);
  tcase_add_test(tc4, eighteen);
  tcase_add_test(tc4, nineteen);

  suite_add_tcase(s4, tc4);
  return s4;
}
