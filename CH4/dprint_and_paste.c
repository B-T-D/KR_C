/* Example debugging print macro */

#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr) 
/* If a parameter name in a #define macro is replaced by a # symbol in the replacement text, the combination will be expanded into a quoted string with the parameter replaced by the actual argument */

#define paste(front, back) front ## back

int main()
{
	double x = 2; 
	double y = 3;
	int name = 0;
	
	dprint(x/y);
	
	printf("%d\n", name);
	
	printf("%d\n", paste(na, me)); /* "pastes" the front and back strings together and then evaluates that as the C code. Macros are changes to the code as displayed, not normal C lines */
	
	//printf("%d\n", name);
	
	
}
