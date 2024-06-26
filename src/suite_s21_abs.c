#include "math_suitecases.h"

START_TEST(abs_1) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(abs_3) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(abs_4) { ck_assert_int_eq(s21_abs(1111111111), abs(1111111111)); }
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("s21_abs");

  tc1 = tcase_create("case_abs");

  tcase_add_test(tc1, abs_1);
  tcase_add_test(tc1, abs_2);
  tcase_add_test(tc1, abs_3);
  tcase_add_test(tc1, abs_4);

  suite_add_tcase(s1, tc1);
  return s1;
}
