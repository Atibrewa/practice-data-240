/*
 * Name: Aahanaa (Atibrewa)
 * File Description: Experimenting with pointers in C!
 */ 
#include <stdio.h>        // printf
#include <stdlib.h>       // free  

// include declarations for functions in binary_convert.c
#include "binary_convert.h"

/*
 * Experimenting with code from class!
 */
int main() {

    // Declaring  Pointer
    int A = 15213;
    int *A_ptr = &A; // int pointer - kind of like an array of bytes
    printf("\nOption 1: Hex value = %X, Decimal value =%d \n", A, A);
    printf("\nOption 2: Hex value = %X, Decimal value =%d \n\n", A_ptr[0], A_ptr[0]);

    unsigned char uc_0x30 = 0x90;
    signed char sc_0x30 = 0x90;

    char *bin_str;
    printf("Interpreting 0x90\n");
    bin_str = uchar_to_bin_str(uc_0x30);
    printf("unsigned char: %2hhu \t%2hhx \t%s\n", uc_0x30, uc_0x30, bin_str);
    free(bin_str);

    bin_str = char_to_bin_str(sc_0x30);
    printf("signed char: %2hhd \t%2hhx \t%s\n\n", sc_0x30, sc_0x30, bin_str);
    free(bin_str);

}