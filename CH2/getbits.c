#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

int main()
{
	unsigned x = 128;
	
	printf("%u\n",x);
	
	printf("%u\n", getbits(x, 7, 3)); /* Evaluates the return as a binary number, then prints the decimal version. So getbits on the number 128 (10000000), getting the 3 bits starting from position 7 (100) will print "4".
}
