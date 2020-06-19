#include <stdio.h>

/* "function prototype" statement: */
float f2c(float f); /* Return type is float, one arg, a float of the Fahrenheit temperature to convert */

/* Test the f2c conversion function */
main()
{
	float i;
	
	for (i = 0.0; i <= 300.0; i = i + 20.0)
		printf("%.1f %.1f\n", i, f2c(i)); // one decimal place
	return 0;
}

/* f2c: convert fahrenheit temperature f to a celsius temperature */
float f2c(float f)
{
	return (5.0/9.0) * (f-32.0);
}
