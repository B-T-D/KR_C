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
	int i, p;
	
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base; /* You literally walk up the increasing exponent values until you hit n. For 2^5 you do 2^1, then 2^2, etc. */
		/* You can't just say 'return base ** n', because there's no ** operator. You literally have to do 'multiply base by itself n times. */
	return p;
}
 
