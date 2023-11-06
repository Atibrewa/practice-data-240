/*
 * binary_convert.c
 * 
 * Author:  Libby Shoop
 * 
 * Functions that determine the bit representation of values of the C integral types:
 * 
 *    char, short, int, long
 * and the unsigned versions of each
 * 
 * a special conversion for half a byte, or a nibble, is also included.
 * 
 * Note: some of this code will make more sense a bit later in the course,
 *       and you will see some of it even later in the semester.
 *       So you do not have to read and understand this all yet.
 * 
 * Important: each of these functions allocates memory for the string that it
 *            returns, so when you are done using the string in your code,
 *            you need to 'free' it. (stdlib.h)
 */
#include <stdlib.h>   // size_t (from stddef.h included within stdlib.h), malloc
#include <stdio.h>    // printf
#include <string.h>    // strcat and strcpy

#include "binary_convert.h"


// private to this file, so left out of binary_convert.h
char * convert_to_string(long val, int bits);

///////////////////////////////  nibble convert
/**
 * Given an input unsigned integer that must be >= 0 and < 16,
 * return a string that represents the 4 bits of the half byte
 * input value. If parameter val is >= 16, this function
 * returns the string "INVALID". 
 * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * nibble_to_bin_str(unsigned int val) {
	char * result;
	if (val < 16) {
		size_t bits = 4;   // half a byte is 4 bits
		
		result = convert_to_string((long)val, bits); // mem alloc inthis function
		
	} else {
		result = (char *)malloc(sizeof(char) * 8);
		strcpy(result, "INVALID");
	}
	return result;
}

/////////////////////////////// char convert
/**
 * Given a char, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
 * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * char_to_bin_str(char val) {
	size_t bytes = sizeof(char);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// unsigned char convert
/**
 * Given an unsigned char, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * uchar_to_bin_str(unsigned char val) {
	size_t bytes = sizeof(unsigned char);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// short convert
/**
 * Given a short, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * short_to_bin_str(short val) {
	size_t bytes = sizeof(short);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// unsigned short convert
/**
 * Given an unsigned short, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * ushort_to_bin_str(unsigned short val) {
	size_t bytes = sizeof(unsigned short);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// int convert
/**
 * Given a int, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
 * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * int_to_bin_str(int val) {
	size_t bytes = sizeof(int);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// unsigned int convert
/**
 * Given an unsigned int, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * uint_to_bin_str(unsigned int val) {
	size_t bytes = sizeof(unsigned int);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// long convert
/**
 * Given a long, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * long_to_bin_str(long val) {
	size_t bytes = sizeof(long);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

/////////////////////////////// unsigned long convert
/**
 * Given an unsigned char, return a string that represents the binary
 * value so that it can be printed. The string is a 'pretty'
 * version of the binary value of the number, with a space between every
 * 4 bits.
  * 
 * Memory is allocated for the return string and must be freed after use.
 */
char * ulong_to_bin_str(unsigned long val) {
	size_t bytes = sizeof(unsigned long);
	size_t bits = bytes << 3;      // shift left by 3 is same as *8
	
	char * result = convert_to_string((long)val, bits);
 
	return result;
}

//////////////////////////////// designed to be reused by each function above
/*
 * Convert a val of length bits into a string.
 * The string should already be long enough to hold a 
 * "pretty" version, where every 4 bits are separated by a space.
 */
char * convert_to_string(long val, int bits) {
	// note that the input is a long so that we can convert any possible integral
	// type using this one function
	
	// will create the string with a space after every 4th bit,
	// so add extra length and a space for the trailing null.
	int pretty_length = bits + bits/4 +1;
	char * result = (char *)malloc(sizeof(char) * pretty_length);
	strcpy(result, "");
	
	// later on you will see why we 'widen' to use long values
	// to ensure that all lengths work
	long bit;
	long one = 1;
	
	for(int i = bits-1; i >= 0; --i) {
		
		// this operation will be clearer later
		bit = val & (one << i);
	
		if (bit) {
			strcat(result, "1");
		} else {
			strcat( result, "0");
		}	
		
		if (i%4 == 0 && i > 0) {
			strcat(result, " ");
		}
		
	}
	
	return result;
}
