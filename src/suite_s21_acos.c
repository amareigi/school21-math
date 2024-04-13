#include "math_suitecases.h"

START_TEST(one) {
  double num = 0.35;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(two) {
  double num = -1.;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(three) {
  double num = -INFINITY;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(four) {
  double num = NAN;
  int suc = 0;
  if (isnan(s21_acos(num)) && isnan(acos(num))) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(five) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(six) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), S21_EPS);
}
END_TEST

START_TEST(seven) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), S21_EPS);
}
END_TEST

START_TEST(eight) { ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPS); }
END_TEST

START_TEST(nine) { ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPS); }
END_TEST

START_TEST(ten) {
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), S21_EPS);
}
END_TEST

Suite *suite_s21_acos(void) {
  Suite *s2;
  TCase *tc2;
  s2 = suite_create("s21_acos");
  tc2 = tcase_create("case_acos");

  tcase_add_test(tc2, one);
  tcase_add_test(tc2, two);
  tcase_add_test(tc2, three);
  tcase_add_test(tc2, four);
  tcase_add_test(tc2, five);
  tcase_add_test(tc2, six);
  tcase_add_test(tc2, seven);
  tcase_add_test(tc2, eight);
  tcase_add_test(tc2, nine);
  tcase_add_test(tc2, ten);

  suite_add_tcase(s2, tc2);
  return s2;
}
