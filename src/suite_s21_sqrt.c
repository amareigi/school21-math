#include "math_suitecases.h"

START_TEST(two) {
  long double a = 0.0;
  long double res1 = sqrt(a);
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_eq_tol(res1, res2, 6);
}
END_TEST

START_TEST(three) {
  long double a = -1.0;
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(four) {
  long double a = 0.5;
  long double res1 = sqrt(a);
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_eq_tol(res1, res2, 6);
}
END_TEST

START_TEST(five) {
  long double a = NAN;
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(six) {
  long double a = INFINITY;
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(eight) {
  long double a = -123456789;
  long double res2 = s21_sqrt(a);
  ck_assert_ldouble_nan(res2);
}
END_TEST

Suite *suite_s21_sqrt(void) {
  Suite *s2;
  TCase *tc2;
  s2 = suite_create("s21_sqrt");
  tc2 = tcase_create("case_sqrt");

  tcase_add_test(tc2, two);
  tcase_add_test(tc2, three);
  tcase_add_test(tc2, four);
  tcase_add_test(tc2, five);
  tcase_add_test(tc2, six);
  tcase_add_test(tc2, eight);

  suite_add_tcase(s2, tc2);
  return s2;
}