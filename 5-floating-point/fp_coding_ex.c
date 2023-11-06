#include <stdio.h>
#include <string.h>

/*
 *  This is an example for bit-level encoding of floats
 */

/* use typedef so that an unsigned value becomes the bits for a
  hypothetical floting point representation
 */
typedef unsigned float_bits;

/*
 * This fnction takes an unsigned value and checks to see if its
 * binary form represents a normalized or denormalized floating
 * point number.
 * paramter: f   is a 32-bit representation of some IEEE single precision number
 *
 * returns: an unsigned value that is  +/-0  if f is a denormalized number
 *          OR returns f itself if it is a normalized number
 */
float_bits float_denorn_zero(float_bits f) {
  /* Decompose bit representation into parts */
  unsigned sign = f>>31;
  unsigned exp =  f>>23 & 0xFF;
  unsigned frac = f     & 0x7FFFFF;

  if (exp == 0) {  // denormalized
    frac = 0;
  }

  return (sign << 31) | (exp << 23) | frac ;
}

// Returns zero if intinity or not a number, prints which one it is
// else returns the number itself
float_bits float_NaN_Inf(float_bits f) {
  /* Decompose bit representation into parts */
  unsigned sign = f>>31;
  unsigned exp =  f>>23 & 0xFF;
  unsigned frac = f     & 0x7FFFFF;

  if (exp == 0xFF && frac == 0) {  // infinity
    printf("Infinity\n");
    return 0;
  } else if (exp == 0xFF && frac != 0) { // NaN
    printf("NaN\n");
    return 0;
  }
  
  return f;
}

// TODO: you complete this
/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
  if (!float_NaN_Inf(f)) { // f is NaN
    return f;
  }

  unsigned neg = f ^ 0x80000000;
  return neg;
}

/* begin show_bytes*/
typedef unsigned char *byte_pointer;

/*
 * prints out len bytes in a memory value pointed to by start
 *
 */
void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
	     printf(" %.2x", start[i]);    // function designed to print
    printf("\n");
}

/*
 *  Use show_bytes on a float representation
 */
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}
/* end show_bytes code */

// In case you want to look at the binary string representation:
/*
 *
 *  This function creates a string representing the binary
 *  number that is stored for a given input integer.
 *  This is placed in the character string passed in called result.
 *  result must be 1 character longer than the string of bits,
 *  whose length is num_bits.
 */
 void binary(unsigned int input, char* result) {
   	//initialize the binary string
 	strcpy(result, "");

 	int i;
 	for(i = (sizeof(unsigned int)*8) - 1; i >= 0; --i) {
 		if(input & (1 << i)) {
 			strcat(result, "1");
 		} else {
 			strcat(result, "0");
 		}
 		// easier to read with spaces after 4 each bits
 		if (i%4 == 0 && i > 0) {
 			strcat(result, " ");
 		}

 	}
 }
