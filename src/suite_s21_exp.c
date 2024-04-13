#include "math_suitecases.h"

START_TEST(exp_1) {
  double x = 0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_2) {
  double x = 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 4;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = -4;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = 1.3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = -1.3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = 0.4;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = -0.4;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = 825;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_10) {
  double x = -825;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = 'T';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'Y';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = 2;
  ck_assert_float_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = -650;
  ck_assert_float_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double num = NAN;
  ck_assert_ldouble_nan(exp(num));
}
END_TEST

START_TEST(exp_17) {
  double num = INFINITY;
  ck_assert_ldouble_eq(exp(num), s21_exp(num));
}
END_TEST

START_TEST(exp_18) {
  double num = -INFINITY;
  ck_assert_ldouble_eq(exp(num), s21_exp(num));
}
END_TEST

Suite *suite_s21_exp(void) {
  Suite *s_exp;
  TCase *tc_exp;
  s_exp = suite_create("s21_exp");

  tc_exp = tcase_create("case_exp");

  tcase_add_test(tc_exp, exp_1);
  tcase_add_test(tc_exp, exp_2);
  tcase_add_test(tc_exp, exp_3);
  tcase_add_test(tc_exp, exp_4);
  tcase_add_test(tc_exp, exp_5);
  tcase_add_test(tc_exp, exp_6);
  tcase_add_test(tc_exp, exp_7);
  tcase_add_test(tc_exp, exp_8);
  tcase_add_test(tc_exp, exp_9);
  tcase_add_test(tc_exp, exp_10);
  tcase_add_test(tc_exp, exp_11);
  tcase_add_test(tc_exp, exp_12);
  tcase_add_test(tc_exp, exp_13);
  tcase_add_test(tc_exp, exp_14);
  tcase_add_test(tc_exp, exp_15);
  tcase_add_test(tc_exp, exp_16);
  tcase_add_test(tc_exp, exp_17);
  tcase_add_test(tc_exp, exp_18);

  suite_add_tcase(s_exp, tc_exp);
  return s_exp;
}
