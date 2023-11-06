/*
 * Aahanaa (Atibrewa)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// found in binary_convert.c
#include "binary_convert.h"

// in this file
void shifting_char(unsigned char x, int lshift, int rshift);
void shifting_short(unsigned short x, int lshift, int rshift);

int main() {
	
	unsigned char x = 0xC3;
	signed char y = (char) x;
	unsigned char uresult;  // for result of logical operation
	char sresult;           // for result of arithmetic operation
	
	char * result_str;   //for binary strings
	char * bin_str_x;
	
	printf("x\t\t\tx<<3\t\t\tx>>2\t\t\ty>>2\n");
	printf("Hex\tBinary\t\tHex\tBinary\t\tHex\tBinary\t\tHex\tBinary\n\n");
	
	////////////////////////   First Example
	// x
	bin_str_x = uchar_to_bin_str(x);
	printf("%hhX\t%s\t", x, bin_str_x);  //print without a newline
	// x << 3
	uresult = x << 3;
	result_str = uchar_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str);  //print without a newline 
	// x >> 2
	uresult = x >> 2;
	free(result_str);
	result_str = uchar_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str);  //print without a newline 
	// y >> 2
	sresult = y >> 2;
	free(result_str);
	result_str = uchar_to_bin_str(sresult);
	printf("%hhX\t%s\n", sresult, result_str);  //print with a newline
	
	free(result_str);
	free(bin_str_x);
	//////////////////////// end first example
	
	// continue with more examples here
	shifting_char(x,3,2);

	unsigned char x2 = 0x75;
	shifting_char(x2,3,2);

	unsigned char x3 = 0x87;
	shifting_char(x3,3,2);

	unsigned char x4 = 0x66;
	shifting_char(x4,3,2);
	
	unsigned short a = 0x8c36;
	unsigned short b = 0x0117;
	unsigned short c = 0x076d;

	shifting_short(b,4,1);
	shifting_short(a,1,5);
	shifting_short(c,7,1);

	return 0;
}

void shifting_char(unsigned char x, int lshift, int rshift) {
	signed char y = (char) x;
	unsigned char uresult;  // for result of logical operation
	char sresult;           // for result of arithmetic operation

	char * result_str;   //for binary strings
	char * bin_str_x;

	printf("\nx\t\t\tx<<%d\t\t\tx>>%d\t\t\ty>>%d\n", lshift, rshift, rshift);
	printf("Hex\tBinary\t\tHex\tBinary\t\tHex\tBinary\t\tHex\tBinary\n\n");

	// x
	bin_str_x = uchar_to_bin_str(x);
	printf("%hhX\t%s\t", x, bin_str_x);

	// logical left shift
	uresult = x << lshift;
	result_str = uchar_to_bin_str(uresult);
	printf("%hX\t%s\t", uresult, result_str); 

	// logical right shift
	uresult = x >> rshift;
	free(result_str);
	result_str = uchar_to_bin_str(uresult);
	printf("%hX\t%s\t", uresult, result_str);

	// arithmetic right shift
	sresult = y >> rshift;
	free(result_str);
	result_str = uchar_to_bin_str(sresult);
	printf("%hX\t%s\n", sresult, result_str);  //print with a newline
	
	free(result_str);
	free(bin_str_x);
}

void shifting_short(unsigned short x, int lshift, int rshift) {
	signed short y = (short) x;
	unsigned short uresult;  // for result of logical operation
	short sresult;           // for result of arithmetic operation

	char * result_str;   //for binary strings
	char * bin_str_x;

	printf("\nx\t\t\t\tx<<%d\t\t\t\tx>>%d\t\t\t\ty>>%d\n", lshift, rshift, rshift);
	printf("Hex\tBinary\t\t\tHex\tBinary\t\t\tHex\tBinary\t\t\tHex\tBinary\n\n");

	// x
	bin_str_x = ushort_to_bin_str(x);
	printf("%hX\t%s\t", x, bin_str_x);

	// logical left shift
	uresult = x << lshift;
	result_str = ushort_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str); 

	// logical right shift
	uresult = x >> rshift;
	free(result_str);
	result_str = ushort_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str);

	// arithmetic right shift
	sresult = y >> rshift;
	free(result_str);
	result_str = ushort_to_bin_str(sresult);
	printf("%hhX\t%s\n", sresult, result_str);  //print with a newline
	
	free(result_str);
	free(bin_str_x);
}
