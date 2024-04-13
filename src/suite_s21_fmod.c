#include "math_suitecases.h"

START_TEST(s21_fmod_test_1) {
  ck_assert_ldouble_eq(s21_fmod(5.55, 6.66), fmod(5.55, 6.66));
}
END_TEST

START_TEST(s21_fmod_test_2) {
  ck_assert_ldouble_eq(s21_fmod(-5.55, -6.66), fmod(-5.55, -6.66));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  double num = 0.0;
  long double orig_res = fmod(num, num);
  long double s21_res = s21_fmod(num, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(s21_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_4) {
  double num = NAN;
  long double orig_res = fmod(num, 2.0);
  long double s21_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(s21_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_5) {
  double num = NAN;
  long double orig_res = fmod(2.0, num);
  long double s21_res = s21_fmod(2.0, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(s21_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_6) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *s10;
  TCase *tc10;
  s10 = suite_create("s21_fmod");

  tc10 = tcase_create("case_fmod");

  tcase_add_test(tc10, s21_fmod_test_1);
  tcase_add_test(tc10, s21_fmod_test_2);
  tcase_add_test(tc10, s21_fmod_test_3);
  tcase_add_test(tc10, s21_fmod_test_4);
  tcase_add_test(tc10, s21_fmod_test_5);
  tcase_add_test(tc10, s21_fmod_test_6);

  suite_add_tcase(s10, tc10);
  return s10;
}
