#include <stdio.h>

/* Print Celsius to Fahrenheit table.*/

main()
{
	float celsius, fahr;
	int lower, upper, step;
	
	lower = -16;
	upper = 150;
	step = 10;
	
	printf("%3s\t%6s\n", "Celsius", "Fahr.");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius / (5.0/9.0)) + 32;
		printf("%3.1f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
