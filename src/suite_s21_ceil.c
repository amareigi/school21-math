#include "math_suitecases.h"

START_TEST(ceil_1) { ck_assert_ldouble_eq(s21_ceil(21.01), ceil(21.01)); }
END_TEST

START_TEST(ceil_2) { ck_assert_ldouble_eq(s21_ceil(-21.01), ceil(-21.01)); }
END_TEST

START_TEST(ceil_3) { ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY)); }
END_TEST

START_TEST(ceil_4) {
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceil_5) { ck_assert_ldouble_eq(s21_ceil(-0.07), ceil(-0.07)); }
END_TEST

START_TEST(ceil_6) { ck_assert_ldouble_nan(s21_ceil(NAN)); }
END_TEST

START_TEST(ceil_7) { ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0)); }
END_TEST

START_TEST(ceil_8) { ck_assert_ldouble_eq(s21_ceil(-0.0), ceil(-0.0)); }
END_TEST

Suite *suite_s21_ceil(void) {
  Suite *s_ceil = suite_create("Suit_Ceil");
  TCase *tc_ceil = tcase_create("Test_Case_Ceil");

  tcase_add_test(tc_ceil, ceil_1);
  tcase_add_test(tc_ceil, ceil_2);
  tcase_add_test(tc_ceil, ceil_3);
  tcase_add_test(tc_ceil, ceil_4);
  tcase_add_test(tc_ceil, ceil_5);
  tcase_add_test(tc_ceil, ceil_6);
  tcase_add_test(tc_ceil, ceil_7);
  tcase_add_test(tc_ceil, ceil_8);
  suite_add_tcase(s_ceil, tc_ceil);
  return s_ceil;
}
