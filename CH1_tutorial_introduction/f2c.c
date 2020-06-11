/* Print a table of Fahrenheit temperatures and their centigrade
equivalents.*/
# include <stdio.h>

main()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0; // lower limit of temperature table
	upper = 300; //upper limit
	step = 20; // step size
	
	fahr = lower;
	while (fahr <= upper) {
celsius = 5 * (fahr - 32) / 9; // Indentation levels...
			printf("%3d\t%6d\n", fahr, celsius); // ...are irrelevant...
		fahr = fahr + step; //...to the compiler. 
	}
}
