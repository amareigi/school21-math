CC = gcc
FLAG_C = -c
FLAG_O = -o
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
s21_MATH_C = s21_*.c 
s21_MATH_O = s21_*.o
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lcheck suite_cases.a s21_math.a -lgcov -lm -lsubunit


all: clean gcov_report

s21_math.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_MATH_C) 
	ar rc s21_math.a $(s21_MATH_O)
	ranlib s21_math.a

test: s21_math.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
	ar rc suite_cases.a $(SUITE_CASES_O)
	ranlib suite_cases.a
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATH_C) main.o $(FLAG_TESTS)
	./tests

gcov_report: test
	gcovr --html-details -o report.html

cpp_check:
	cppcheck --enable=all --force *.h *.c

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
