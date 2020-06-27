/* strlen function with array-name-pointer parameter */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define intprint(expr) printf(#expr " = %d\n", expr)

/* my_strlen: return length of string s */
int my_strlen(char *s) /* This is identical to the parameter being (char s[]), for compiler purposes (the function will still treat an array name as a pointer as needed). K&R say better to make explicit that the parameter is a pointer. */

{
	int n;
	
	for (n = 0; *s != '\0'; s++) /* Increments the pointer to point to the next character 
			(incrementing the function's private copy of the pointer, so doesn't change the pointer in 					the code that called the function )*/
		n++;
	return n;
}

int main()
{
	int c, i, length;
	char string[MAXLINE] = "test";
	char *sp = &string[0]; /* pointer to the string */
	
	printf("%s\n", string);
	
	length = my_strlen(sp);
	intprint(length);
	
	
	
	
	
	
}
