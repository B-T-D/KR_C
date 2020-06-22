#include <stdio.h>

#define MAXLINE 1000

/* External globally shareable variables: */
int max;
char line[MAXLINE];
char longest[MAXLINE];
/* These ^ were defined within main in the first version of longest */

int get_line(void);
void copy(void);

/* Print longest input line */
main()
{
	int len;
	extern int max;
	extern char longest[];
	
	max = 0;
	while ((len = get_line()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0) //There was a line
		printf("%s", longest);
	return 0;
}

/* get_line function rewritten to use the globals */
int get_line(void)
{
	int c, i;
	extern char line[];
	
	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: updated version of the copy function */
void copy(void)
{
	int i;
	extern char line[], longest[];
	
	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
