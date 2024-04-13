#include "s21_math.h"

long double s21_fact(int count) {
  if (count < 0) {
    return 0;
  } else if (count == 0) {
    return 1;
  } else {
    long double res = 1;
    int i = 1;
    while (i <= count) {
      res = res * i;
      i++;
    }
    return res;
  }
}