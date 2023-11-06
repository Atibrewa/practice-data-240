/*
 *  COMP 240 example code to illustrate how we can manipulate bytes in C
 *   and see how they are stored for various data types.
 *
 *  original author:  Bryant and O'Hallaran
 *  updated by: Libby Shoop
 */

#include <stdio.h>   // printf
#include <stdlib.h>  // atoi, strtol
        //  see: http://www.tutorialspoint.com/c_standard_library/stdlib_h.htm
#include <string.h>  // strlen

/******************************************************************************
 *  Some notes about style:
 *  	-Don't have your lines be any longer than 80-90 characters
 *  	 (many editors show a column number and can indicate the right 
 *        edge for you)
 *  	-Have a descriptive comment for each function
 *  	-Describe typedef definitions
 *  	-comment inline when explanation is warranted
 *  	-Always make sure that your main function returns 0 if successful
 *  	-sometimes comments made of a repeated character are useful to break
 *  	 sections, such as those around these notes
 *****************************************************************************/

/****************  begin show-bytes section ********************************/
// This typedef is called byte pointer because an unsigned char is one byte
// and an unsigned char * is denoting a pointer to a byte
typedef unsigned char *byte_pointer; 

/*
 * Beginning at the byte pointed to by start, print the hexedecimal
 * values of the next len bytes.
 */
void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
		// printf(" %.2x", start[i]);    //line:data:show_bytes_printf
        printf("%p\t0x%.2x\n", start + i, start[i]);     //prints pointer address in hex, value at the address in hex
    printf("\n");

}

/*
 * Wrapper around show_bytes for an input integer parameter, x.
 * 
 */
void show_int(int x) {
    // since x is an int, &x is a pointer to its first byte
    // sizeof operator returns the number of bytes of the given type
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

/*
 * Wrapper around show_bytes for an input float parameter, x.
 * 
 */
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

/*
 * Wrapper around show_bytes for an input void* parameter, x.
 * 
 * A pointer of type void * represents the address of an object in memory,
 * but not its type. Here we use it as a means of displaying the hexadecimal
 * value of the bytes representing an actual pointer to a position in memory.
 * 
 */
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}

/*
 * Wrapper around show_bytes for an input long parameter, x.
 * 
 */
void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}

/****************  end show-bytes section   ***********************************/


/************ begin section where we:
		test how show-bytes works and
		examine byte storage
******************************************************/

/*
 *  Given an integer, show the headecimal values of each byte of these values:
 *    1. the int itself
 *    2. the int after being cast to a float  (a potentially damgerous operation)
 *    3. the pointer where this int is stored in memory
 */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* $end test-show-bytes */

/*
 *  What will the result of this function reveal about how the bytes of an
 *  integer are stored?
 */
void simple_show_a() {
/* $begin simple-show-a */
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes(valp, 1); /* A. */
	show_bytes(valp, 2); /* B. */
	show_bytes(valp, 3); /* C. */
/* $end simple-show-a */
}


/*
 *  What will the result of this function reveal about how the bytes of an
 *  integer are stored?
 */
void simple_show_b() {
/* $begin simple-show-b */
	int val = 0x12345678;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes(valp, 1); /* A. */
	show_bytes(valp, 2); /* B. */
	show_bytes(valp, 3); /* C. */
/* $end simple-show-b */
}

/*
 *  A couple more tries where we are casting ints to floats.
 */
void float_eg() {
  int x = 3490593;
  float f = (float) x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);

  x = 3510593;
  f = (float) x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);

}

/*
 * An upper-case string
 */
void string_ueg() {
/* $begin show-ustring */
	const char *s = "ABCDEF";
	show_bytes((byte_pointer) s, strlen(s)); 
/* $end show-ustring */
}

/*
 * A lower-case string
 */
void string_leg() {
/* $begin show-lstring */
	const char *s = "abcdef;";
	show_bytes((byte_pointer) s, strlen(s)+1); 
/* $end show-lstring */
}

/*
 *  negative values of short and int data types have
 *  two's complement representation.
 */
void show_twocomp() 
{
/* $begin show-twocomp */
    short x = 12345; 
    short mx = -x; 
    
    show_bytes((byte_pointer) &x, sizeof(short)); 
    show_bytes((byte_pointer) &mx, sizeof(short)); 
/* $end show-twocomp */
}

void test_show_long()
{
    long x = 4452;
    show_long(x);
}

