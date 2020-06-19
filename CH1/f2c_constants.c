#include <stdio.h>

/* Example of constants ("symbolic constants"): */
# define LOWER 0 // Lower limit of table
# define UPPER 300 // Upper limit
# define STEP 20 // Step size

	/* No semicolons at end of define lines. 
	"Symbolic constants" != variables. */

/* Print Fahrenheit-Celsius table using a for loop */
main()
{
	int fahr;
	
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
