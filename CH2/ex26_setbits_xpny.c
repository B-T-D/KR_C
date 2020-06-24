/* Write a function that returns x with the n bits that begin at position p set to the rightmost n bits of y */

#include <stdio.h>

//unsigned setbits(x, p, n, y);

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p+1-n)) | /* "OR them together"--use the bitwise or to combine */
		(y & ~(~0 << n)) << (p+1-n);
}

int main()
{
	/*
	x = 175 = 10101111
	p = 6
	n = 3
	y = 107 = 01101011
	expected = 1011111 = 191
	*/
	
	unsigned x = 175, y = 107;
	int p = 6, n = 3;
	printf("%u\n", x);
	x = setbits(x, p, n, y);
	printf("%u\n", x);
	
}

