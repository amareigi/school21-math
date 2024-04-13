#include "math_suitecases.h"

START_TEST(floor_1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor_2) { ck_assert_ldouble_eq(s21_floor(21.01), floor(21.01)); }
END_TEST

START_TEST(floor_3) { ck_assert_ldouble_eq(s21_floor(5.91), floor(5.91)); }
END_TEST

START_TEST(floor_4) { ck_assert_ldouble_eq(s21_floor(-21.01), floor(-21.01)); }
END_TEST

START_TEST(floor_5) { ck_assert_ldouble_eq(s21_floor(-5.91), floor(-5.91)); }
END_TEST

START_TEST(floor_6) { ck_assert_ldouble_nan(s21_floor(NAN)); }
END_TEST

START_TEST(floor_7) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor_8) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(floor_9) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s_floor;
  TCase *tc_floor;
  s_floor = suite_create("s21_floor");

  tc_floor = tcase_create("case_floor");

  tcase_add_test(tc_floor, floor_1);
  tcase_add_test(tc_floor, floor_2);
  tcase_add_test(tc_floor, floor_3);
  tcase_add_test(tc_floor, floor_4);
  tcase_add_test(tc_floor, floor_5);
  tcase_add_test(tc_floor, floor_6);
  tcase_add_test(tc_floor, floor_7);
  tcase_add_test(tc_floor, floor_8);
  tcase_add_test(tc_floor, floor_9);

  suite_add_tcase(s_floor, tc_floor);
  return s_floor;
}
