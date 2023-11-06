#Data Activity 4

CC=gcc -std=c99

all: twos_comp check_overflow

twos_comp: test_tc.c binary_convert.c
	${CC} -o twos_comp test_tc.c binary_convert.c

check_overflow: check_overflow.c 
	${CC} -o check_overflow check_overflow.c

clean:
	rm -f twos_comp