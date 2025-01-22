PROJECT_NAME = decimal

CC = gcc 
CFLAGS =-Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Darwin)
    TEST_LIBS = -lcheck -lm
	OP = open
endif

ifeq ($(OS),Linux)
	OP = xdg-open
    TEST_LIBS = -lcheck -lm -lsubunit -lrt -pthread
endif

all: clean s21_decimal.a test gcov_report m_clean

s21_decimal.a:
	$(CC) $(CFLAGS) -c ./cfiles/s21_*.c
	ar rcs s21_decimal.a s21_*.o
	rm ./s21_*.o

clean: m_clean
	rm -rf ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./report ./*.info ./decimal_o ./*.dSYM ./test_s21_decimal ./test

m_clean:
	rm -rf ./*.o ./*.gcno ./*.gcda

format:
	clang-format -style=google -i ./*/*.c ./*/*.h

style:
	clang-format -style=google -n ./*/*.c ./*/*.h

test: s21_decimal.a
	$(CC) $(CFLAGS) -c ./tf/test*.c
	$(CC) *.o s21_decimal.a $(TEST_LIBS) -o test
	rm ./*.o

test_code: test
	./test
	rm ./test
	rm ./*.o
	rm ./*.a

gcov_report: s21_decimal.a
	$(CC) $(CFLAGS) --coverage ./tf/*.c ./cfiles/s21_*.c s21_decimal.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	$(OP) ./report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

rebuild: clean all
	$(OP) ./report/index.html
