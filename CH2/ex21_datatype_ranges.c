/* Determine the ranges (number of bits) of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. */

#include <stdio.h>
#include <limits.h>


/* Print the ranges as listed in limits.h */
int main()
{
	printf("signed char min = %d\n", SCHAR_MIN);
	printf("signed char max = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n", SHRT_MAX);
	printf("signed long min = %ld\n", LONG_MIN);
	printf("signed long max = %ld\n", LONG_MAX);
}
