/* Print all input lines that are longer than 20 characters */

#include <stdio.h>
#define MAXLINE 1000 /* Needed? */
#define PRINTSIZE 20 /* Print lines with more characters than this */

int get_line(char line[], int maxline); /* Naming it "getline" causes some kind of compiler conflict with a builtin thing in stdio.h also named "getline"--maybe added since date of K&R C? */

/* Get the input line and print it if longer than PRINTSIZE */
main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > PRINTSIZE) {
			printf("%s", line);
		}
	return 0;
}

/* get_line: read a line into char array s, return int length */
int get_line(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;		
}
