/*
 * Data activity 4
 * Aahanaa (Atibrewa)
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binary_convert.h"

int main() {
    // some limits: it's best to see what our mchine will give us
    printf("short is %zu bytes wide\n", sizeof(short));
	printf("min value of a short is: %hd\n", SHRT_MIN);
	printf("max value of a short is: %hd\n", SHRT_MAX);
	
	////////////////  two's complement values
	printf("\nA few two's complement values\n");
	
    short tmp = -32767;
	
    char * bin_str;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);
	
	tmp = SHRT_MIN;
	bin_str = short_to_bin_str(tmp); 
    printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = -567;
	bin_str = short_to_bin_str(tmp); 
    printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = 567;
	bin_str = short_to_bin_str(tmp); 
    printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = 32766;
	bin_str = short_to_bin_str(tmp); 
    printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);
	
	////////////////  unsigned integer values
	printf("\nA few unsigned short integer values\n");

	unsigned short utmp;

	utmp = USHRT_MAX;	// Maximum value of unsigned short using limits.h
	bin_str = ushort_to_bin_str(utmp); 
    printf("%hu\t%04hx\t%s\n", utmp, utmp, bin_str);
	free(bin_str);

	utmp = 0;
	bin_str = ushort_to_bin_str(utmp); 
    printf("%hu\t%04hx\t%s\n", utmp, utmp, bin_str);
	free(bin_str);

	utmp = 32767;
	bin_str = ushort_to_bin_str(utmp); 
    printf("%hu\t%04hx\t%s\n", utmp, utmp, bin_str);
	free(bin_str);

	utmp = 32768;
	bin_str = ushort_to_bin_str(utmp); 
    printf("%hu\t%04hx\t%s\n", utmp, utmp, bin_str);
	free(bin_str);

	printf("\n");

	///////////////////////////////// Part 2: Casting
	// The binary values are exactly the same! What changes is how the most significant bit is interpreted
	short int v = -12345;
	unsigned short uv = (unsigned short) v;

	printf("Bit pattern remains exactly the same:");
	printf("v = %hd, uv = %hu\n", v, uv);
	bin_str = short_to_bin_str(v);
	printf("%hd\t%hx\t%s\n", v, v, bin_str);
	free(bin_str);

	bin_str = ushort_to_bin_str(uv);
	printf("%hu\t%hx\t%s\n", uv, uv, bin_str);
	free(bin_str);

	printf("\n");

	// Casting negative value
	v = -45;
	uv = (unsigned short) v;

	printf("Negative numbers become large positive numbers:\n");
	printf("v = %hd, uv = %hu\n", v, uv);
	bin_str = short_to_bin_str(v);
	printf("%hd\t%hx\t%s\n", v, v, bin_str);
	free(bin_str);

	bin_str = ushort_to_bin_str(uv);
	printf("%hu\t%hx\t%s\n", uv, uv, bin_str);
	free(bin_str);

	printf("\n");

	// Casting Positive Value
	v = 565;
	uv = (unsigned short) v;

	printf("Positive numbers remain the same:");
	printf("v = %hd, uv = %hu\n", v, uv);
	bin_str = short_to_bin_str(v);
	printf("%hd\t%hx\t%s\n", v, v, bin_str);
	free(bin_str);

	bin_str = ushort_to_bin_str(uv);
	printf("%hu\t%hx\t%s\n", uv, uv, bin_str);
	free(bin_str);

	// Short to Int: Positive and Negative short
	short sx = 266;
	int ix = (int) sx;

	printf("\nPositive short to int is okay:\n");
	printf("short = %hd, int = %d\n", sx, ix);
	bin_str = short_to_bin_str(sx);
	printf("%hd\t%hx\t%s\n", sx, sx, bin_str);
	free(bin_str);
	bin_str = int_to_bin_str(ix);
	printf("%d\t%x\t%s\n", ix, ix, bin_str);
	free(bin_str);

	sx = -266;
	ix = (int) sx;
	printf("\nNegative short to int is also okay:\n");
	printf("short = %hd, int = %d\n", sx, ix);
	bin_str = short_to_bin_str(sx);
	printf("%hd\t%hx\t\t%s\n", sx, sx, bin_str);
	free(bin_str);
	bin_str = int_to_bin_str(ix);
	printf("%d\t%x\t%s\n", ix, ix, bin_str);
	free(bin_str);

	// Int to Short
	int iz = 65538;
	short sz = (short) iz;
	printf("\nInt to short loses information:\n");
	printf("int = %d, short = %hd,\n", iz, sz);
	bin_str = int_to_bin_str(iz);
	printf("%d\t%x\t%s\n", iz, iz, bin_str);
	free(bin_str);
	bin_str = short_to_bin_str(sz);
	printf("%hd\t%hx\t%s\n\n", sz, sz, bin_str);
	free(bin_str);	

	iz = -65538;
	sz = (short) iz;
	printf("int = %d, short = %hd,\n", iz, sz);
	bin_str = int_to_bin_str(iz);
	printf("%d\t%x\t%s\n", iz, iz, bin_str);
	free(bin_str);
	bin_str = short_to_bin_str(sz);
	printf("%hd\t%hx\t\t%s\n", sz, sz, bin_str);
	free(bin_str);	
	
	///////////////////////////////// Part 3- keep commented until you work on this later
	// create the hexidecimal table for all 1-byte signed numbers 
	signed char i;
	char * bin;   
	printf("\ndecimal\thex\tbinary\n");

    for (i=-128; i<=127; i++) {	
		bin = char_to_bin_str(i);
		printf("%hhd\t%02hhx\t%s\n", i, i, bin);
		free(bin);
		if (i==127) {
			break; // breaks the infinite loop!
		}
	}
	
}
