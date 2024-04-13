#include <math.h>
#include <stdlib.h>

#include "math_suitecases.h"
#include "s21_math.h"

int main(void) {
  Suite *cases[] = {
      suite_s21_abs(),  suite_s21_fabs(),  suite_s21_fmod(), suite_s21_ceil(),
      suite_s21_exp(),  suite_s21_floor(), suite_s21_log(),  suite_s21_acos(),
      suite_s21_asin(), suite_s21_atan(),  suite_s21_sqrt(), suite_s21_sin(),
      suite_s21_cos(),  suite_s21_tan(),   suite_s21_pow(),  NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
