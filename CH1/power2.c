/* Illustrates how to define a function (C lacks the ** exponentiation operator that e.g. Python has */

#include <stdio.h>

int power(int m, int n); /* syntax form:
	return-type function-name(parameter declarations)

/* ^ This line (the "function prototype") is analogous to declaration of a variable, as opposed to that variable's subsequent assignment statement. */
	/* Function name needs to agree, but not the parameter names. Could 	just write power(int, int), the way it's done here is just for 	 	better documentation practice. */

/* test power function */
main()
{
	int i;
	
	for (i = 0; i < 10; ++i) /* This calls the function. NB doesn't matter that main() is defined before the called power() function is defined. */
		printf("%d %d %d\n", i, power(2, i), power(-3,i));
	return 0;
}

/* power: raise base to nth power; n >= 0 */
int power(int base, int n)
{
	/* Don't need to declare a separate i variable as the first one did--"call by value" rather than by reference. */
	int p; 
	
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}
 
