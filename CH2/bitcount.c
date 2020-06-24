/* Return the number of bits in an integer that have the value 1 */

#include <stdio.h>

int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x != 0; x >>= 1) /* x>>=1 is what ends the loop. It iterates over bits until reaching the rightmost bit. If you instead shifted left (x <<= 1), you'd only look at the leftmost bit, then exit the loop. */
		if (x & 01)
			b++;
	return b;
}


/* Faster version from ex29. In a two's complement number system, x &= (x-1) deletes the rightmost bit (right most bit that's a 1). This can be used as a shortcut to make the bitcount algorithm faster. */
int bitcount2(unsigned x)
{
	int b;
	
	for (b = 0; x != 0; x &= x-1)
		++b;
	return b;
}


int main()
{
	unsigned n = 255;
	
	printf("%u\n", n);
	
	printf("%d\n", bitcount(n));
	
	printf("----\n");
	
	printf("%u\n", n);
	
	printf("%d\n", bitcount2(n));
}
