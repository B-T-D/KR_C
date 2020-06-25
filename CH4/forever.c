/* A for loop controlled by (;;) will loop infinitely */

/* Unrelated sandboxing for other nearby in text example */

#include <stdio.h>

#define square(x) x * x
//#undef square(x)

void forever();

int main()
{
	
	printf("%d\n", square(2));
	printf("%d\n", square(2+3)); /* outputs 11.  
		2 + 3 * 2 + 3 --> operator precedence --> 2 + 6 + 3 = 11 */
	//forever();	
	
}

void forever()
{
	for (;;)
		printf("looping ");
}
