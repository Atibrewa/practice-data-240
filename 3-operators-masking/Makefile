#Aahanaa (Atibrewa)
#You will fill this in yourself for practice
#Ultimately it should build and clean three executable programs
CC=gcc -std=c11

all: bit_logical mask shifts          #other program executables will go here

bit_logical: bit_logical.c binary_convert.c binary_convert.h
	${CC} -o bit_logical binary_convert.c bit_logical.c

mask: mask.c binary_convert.c binary_convert.h
	${CC} -o mask binary_convert.c mask.c

shifts: shifts.c binary_convert.c binary_convert.h
	${CC} -o shifts binary_convert.c shifts.c

clean:
	rm -f bit_logical