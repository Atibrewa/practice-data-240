// Aahanaa Tibrewal (Atibrewa)

#include <stdio.h>        // printf
#include <stdlib.h>       // free  
#include <assert.h>       // assert

// include declarations for functions in binary_convert.c
#include "binary_convert.h"

/*
 * A program that uses the bitwise and logical operators
 * and compares how they work.
 * Bitwise operators are printed using binary_convert.c
 * Logical operations are verified using assert()
 * 
 */
int main() {

    unsigned char x = 0x66;
    unsigned char y = 0x39;

    // Testing bitwise operators and printing output using binary_convert.c
    printf("Bitwise AND:\n");
    unsigned char result = x & y;
    printf("%s  & \n%s \n--------\n%s \t%hhx\n\n", 
        uchar_to_bin_str(x), uchar_to_bin_str(y), 
        uchar_to_bin_str(result), result);
    
    printf("Bitwise OR:\n");
    result = x | y;
    printf("%s  | \n%s \n--------\n%s \t%hhx\n\n", 
        uchar_to_bin_str(x), uchar_to_bin_str(y), 
        uchar_to_bin_str(result), result);
    
    result = ~x | ~y;
    printf("%s  | \n%s \n--------\n%s \t%hhx\n\n", 
        uchar_to_bin_str(~x), uchar_to_bin_str(~y), 
        uchar_to_bin_str(result), result);
    // Bitwise ends here

    // Logical operators and assert()
    result = x & !y;
    assert(result == 0);

    result = x && y;
    assert(result == 0x01);

    result = x || y;
    assert(result == 0x01);

    result = !x || !y;
    assert(result == 0);

    result = x && ~y;
    assert(result == 0x01);

    return 0;
}