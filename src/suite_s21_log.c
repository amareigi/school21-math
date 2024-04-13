#include "math_suitecases.h"

START_TEST(log_1) { ck_assert_ldouble_infinite(s21_log(INFINITY)); }
END_TEST

START_TEST(log_2) { ck_assert_ldouble_nan(s21_log(-INFINITY)); }
END_TEST

START_TEST(log_3) { ck_assert_ldouble_nan(s21_log(NAN)); }
END_TEST

START_TEST(log_4) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(log_5) {
  ck_assert_ldouble_eq_tol(s21_log(0.001), log(0.001), 1e-6);
}
END_TEST

START_TEST(log_6) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_7) { ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6); }
END_TEST

START_TEST(log_8) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_9) { ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6); }
END_TEST

START_TEST(log_10) {
  ck_assert_ldouble_eq_tol(s21_log(999999999.000000001),
                           log(999999999.000000001), 1e-6);
}
END_TEST

START_TEST(log_11) {
  ck_assert_ldouble_eq_tol(s21_log(0.1e-16), log(0.1e-16), 1e-6);
}
END_TEST

START_TEST(log_12) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-6);
}
END_TEST

Suite *suite_s21_log(void) {
  Suite *s_log;
  TCase *tc_log;
  s_log = suite_create("s21_log");

  tc_log = tcase_create("case_log");

  tcase_add_test(tc_log, log_1);
  tcase_add_test(tc_log, log_2);
  tcase_add_test(tc_log, log_3);
  tcase_add_test(tc_log, log_4);
  tcase_add_test(tc_log, log_5);
  tcase_add_test(tc_log, log_6);
  tcase_add_test(tc_log, log_7);
  tcase_add_test(tc_log, log_8);
  tcase_add_test(tc_log, log_9);
  tcase_add_test(tc_log, log_10);
  tcase_add_test(tc_log, log_11);
  tcase_add_test(tc_log, log_12);
  suite_add_tcase(s_log, tc_log);
  return s_log;
}
