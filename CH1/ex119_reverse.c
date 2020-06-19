/* Write function that reverses a character string. Then have the program reverse its input 
one line at a time. */

#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int len(char s[]); /* Return the length of a string */

main()

{
	char s[MAXLINE];
	int i;
	
	/*s[0] = 's';
	s[1] = 'p';
	s[2] = 'a';
	s[3] = 'm';
	s[4] = '\0';*/
	
	/*s[0] = 'p';
	s[1] = 'y';
	s[2] = 't';
	s[3] = 'h';
	s[4] = 'o';
	s[5] = 'n';
	s[6] = '\0';*/
	
	/* Odd number of chars: */
	s[0] = 'r';
	s[1] = 'i';
	s[2] = 't';
	s[3] = 'c';
	s[4] = 'h';
	s[5] = 'i';
	s[6] = 'e';
	s[7] = '\0';
	

	printf("From main before calling reverse:\n\t%s\n",s);
	
	reverse(s);
	
	printf("From main after calling reverse:\n\t%s\n", s);
	
}

void reverse(char s[])
{
	int length, i, c1, c2;
	
	length = len(s);	
	
	for (i=0; i < (length / 2); ++i) {
		c1 = s[i]; 
		c2 = s[(length - i) - 1];
		s[i] = c2;
		s[(length - i) - 1] = c1;
		}
		
}

/* Count the number of non-null characters in string s 
Input "string" must end with a '\0' null character. */
int len(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
	
