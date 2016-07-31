CC=gcc
CFLAGS=-g -Wall

check_numerals: test/check_numerals.c
	$(CC) $(CFLAGS) src/numerals.c test/check_numerals.c -o check_numerals `pkg-config --libs check`

.PHONY: clean
clean:
	$(RM) check_numerals
