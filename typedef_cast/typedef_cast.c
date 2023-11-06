/*
 * Name: Aahanaa (Atibrewa)
 * File Description: Demo activities typedef, storage & pointers as addresses.
 */ 
#include <stdio.h>        // printf
#include <stdlib.h>       // free  

/*
 * Investigate how bytes are stored and implicit casting by printf
 */
int main() {

	// Casting a pointer (P) to unsigned char * create an array containing
	// the bytes used to define the value P is pointing to. For example, 
	// For Little endian, if B = 0x01234567, and *P = &B, the array with 
	// the values [67, 45, 23, 01] 
	printf("\n\nDemo casting pointer to unsigned char * \n");
	int B = 0x01234567;
	int *P = &B;
	unsigned char *array_of_bytes_for_B = (unsigned char * ) P;
	printf("First byte= %.2X \n", array_of_bytes_for_B[0]);
	printf("Last  byte= %.2X \n", array_of_bytes_for_B[3]);
	printf("Pointer value= %p \n", array_of_bytes_for_B);


	printf("\n\nDemo typedef. \n");
	typedef unsigned char one_byte_num;
	one_byte_num x1 = 255;
	printf("x1_hhu=%hhu     x1_u=%u\n\n", x1, x1); 
	// one_byte_num x2 = 256; // TODO 2: This will give a warning. Can you explain why as a comment below?
	//printf("x2_hhu=%hhu     x2_u=%u\n", x2, x2);
    
    /* TODO 2 Explanation
     * We are trying to store the value 256 which requires more than one byte but the data type is
	 * an unsigned char which has a max size of one byte! The max value we can assign to an unsigned char is 255.
     */
    

	printf("Back to printf directives now that we know more. \n");
	int i = 0x18080;
	printf("hhu=%hhu \thhx=%hhx\n", i, i); // Recall 1st bit is 2^0

	// TODO 3: Try the next two lines of code. Can you explain as a comment below why printf prints
	// the values it prints? 
	printf("hu=%hu \thx=%hx\n", i, i);
	printf("u=%u \tx=%x\n", i, i); // int you don't need length e.g. hh
    
    /* TODO 3 Explanation
     * hh -> unsigned char, so it only takes one byte of data, which is two digits of hex
	 * h -> unsigned short int, so it takes two bytes, which is four digits of hex
	 * none (only u or x) -> unsigned int, so it takes upto 4 bytes of data which is more than is needed for the given value
     */

}
