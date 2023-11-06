#include <stdio.h>   // printf
#include <stdlib.h>  // atoi

// This typedef is called byte pointer because an unsigned char is one byte
// and an unsigned char * is denoting a pointer to a byte
typedef unsigned char *byte_pointer; 

// declarations from show-bytes.c
void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);
void test_show_bytes(int val);
void simple_show_a();
void simple_show_b();
void float_eg();
void string_ueg();
void string_leg();
void show_twocomp();
void show_long();
void test_show_long();

/************ main ************************/
/*
 *
 *  In many cases for this course it is a way to show the funtions you write
 *  like those above in action.
 */
int main(int argc, char *argv[])  // set up ti use command-line arguments
{
    int val = 12345;  // default value in case one isn't entered on command line

    
    if (argc > 1) {  // a command line argument was given
	    val = atoi(argv[1]);  // converts the string from the command line into int
	
        // What might happen if we used this with a large number needing
        // more than 4 bytes, like this:
        //val = strtol(argv[1], NULL, 0);
        //
        // Note that val would need to be a long, and a new funtion like
        // test_show_bytes should take that long
    }
    printf("calling test_show_bytes\n");
    test_show_bytes(val);

    printf("calling show_twocomp\n");
    show_twocomp();
    printf("Calling simple_show_a\n");
    simple_show_a();
    printf("Calling simple_show_b\n");
    simple_show_b();
    printf("Calling float_eg\n");
    float_eg();
    printf("Calling string_ueg\n");
    string_ueg();
    printf("Calling string_leg\n");
    string_leg();
    printf("Calling show_long\n");
    test_show_long();

    return 0;  //!! Always make sure that your main function returns 0 if successful
}
