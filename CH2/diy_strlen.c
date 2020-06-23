/* DIY example version of the standard library strlen(s) function--returns length of its character string argument s, excluding the terminal \0. */

#include <stdio.h>
#define MAXLINE 1000

int my_strlen(char s[]);

int main()
{
	char s[MAXLINE];
	int i, c, length;
	
	for (i=0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	
	printf("%s\n", s);
	length = my_strlen(s);
	printf("%d\n", length);
}

/* strlen: return length of s */
int my_strlen(char s[])
{
	int i;
	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}
	
