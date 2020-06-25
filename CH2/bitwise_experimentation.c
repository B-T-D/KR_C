#include <stdio.h>

int main()
{
	int n = 2;
	int * p;
	
	printf("%d\n", n);
	
	n = n << 1; /* shifts 10 to 100 */
	printf("%d\n", n); /* n is now decimal 4 */
	
	n = 5; /* Shifting left 2 is same as multiplying by 4. Doesn't matter if the integer whose bits are shifted is an integer multiple of four */
	n = n << 2; /* Here: 5 = 101. Shifting bits left two gives 10100.
		0*2^0 + 0*2^1 + 1*2^2 + 0*2^3 + 1*2^4
		= 4 + 16
		= 20 */
	printf("%d\n", n); 
	
	n = n >> 2; // shift it back to 5
	printf("shifted back to 5: %d\n", n);
	
	n = ~n;
	
	printf("Printing the one's complement of integer n:\n\t%d\n",
	n);
	
	n = ~n;
	
	printf("One's complement again flips each bit back to what it was before:\n\t%d\n",
	n);

	
	printf("Address of variable n: %p\n", &n);	
	
	n = 511;
	printf("%d\n", n);
	
	printf("%d\n", n & 0177); /* Confirmed that this "sets to zero all but the low-order 7 bits of n--output is 127, i.e. seven bits set to one, any higher bits zero. 0...1111111
}
