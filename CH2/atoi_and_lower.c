

	/* "atoi" name is from "ascii to integer" */

#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c; // if it was already lowercase
}

int main()
{
	int number;
	char s[1000] = "8";
	s[0] = '8';
	//s[1] = '2';
	printf("%d\n", atoi(s));
	
	printf("%c\n", lower('T'));
}
