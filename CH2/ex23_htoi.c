/* Function to convert string of hexadecimal digits to an integer. */

#include <stdio.h>

#define	YES	1
#define	NO	0

/* htoi: convert hexadecimal string s to ingeger */
int htoi(char s[])
{
	int hexdigit, i, inhex, n;
	
	i = 0;
	if (s[i] == '0') { /* If there's a leading 0x or 0X identifier, ignore it */
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i; /* Skip it by simply incrementing i to the next value */
	}
	n = 0;
	inhex = YES; /* Start with assumption that it's valid hex digit char, end of the if else chain handles it if it's not */
	for ( ; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0'; // '0' = 48
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10; // 'a' = 97
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10; 
		else
			inhex = NO; // Not a valid hex digit in 0 through F if this is reached
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

int main()
{
	char hexchars[17] = "0123456789ABCDEF";
	int i;
	char onehex[1];
	
	
	printf("%d\n", htoi("F"));
	

}
