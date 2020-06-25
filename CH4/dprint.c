/* Example debugging print macro */

#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main()
{
	double x = 2;
	double y = 3;
	
	dprint(x/y);
}
