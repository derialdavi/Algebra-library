CC = gcc
CFLAGS = -I../../src -I../unity

SRC = ../../src/complex_numbers.c ../../src/complex_numbers_polar_form.c
TEST_SRC = complex_numbers_tests.c ../unity/unity.c

all: test

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o test_runner $(SRC) $(TEST_SRC) -lm
	./test_runner
	@trap 'rm -f test_runner' EXIT