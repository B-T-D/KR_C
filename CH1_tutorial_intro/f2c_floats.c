/* Improved version of the Fahrenheit to celsius function,
using floating point arithmetic for better accuracy.*/

# include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0; // lower limit of temperature table
	upper = 300; //upper limit
	step = 20; // step size
	
	printf("%3s\t%6s\n", "Fahr.", "Celsius");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius); // 3 and 6 are column widths. .1 in 6.1 means 1 digit after the decimal point.
		fahr = fahr + step;
	}
}
