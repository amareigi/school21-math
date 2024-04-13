#include "math_suitecases.h"

START_TEST(fabs_1) { ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001)); }
END_TEST

START_TEST(fabs_2) {
  ck_assert_ldouble_eq(s21_fabs(-55.555555), fabs(-55.555555));
}
END_TEST

START_TEST(fabs_3) {
  ck_assert_ldouble_eq(s21_fabs(-111111111111.1), fabs(-111111111111.1));
}
END_TEST

START_TEST(fabs_4) {
  ck_assert_ldouble_eq(s21_fabs(111111111111.1), fabs(111111111111.1));
}
END_TEST

START_TEST(fabs_5) { ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY)); }
END_TEST

START_TEST(fabs_6) {
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(fabs_7) {
  double number = NAN;
  long double orig_res = fabs(number);
  long double s21_res = s21_fabs(number);
  int suc = 0;
  if (isnan(orig_res) && isnan(s21_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite *suite_s21_fabs(void) {
  Suite *s8;
  TCase *tc8;
  s8 = suite_create("s21_fabs");

  tc8 = tcase_create("case_fabs");

  tcase_add_test(tc8, fabs_1);
  tcase_add_test(tc8, fabs_2);
  tcase_add_test(tc8, fabs_3);
  tcase_add_test(tc8, fabs_4);
  tcase_add_test(tc8, fabs_5);
  tcase_add_test(tc8, fabs_6);
  tcase_add_test(tc8, fabs_7);

  suite_add_tcase(s8, tc8);
  return s8;
}
