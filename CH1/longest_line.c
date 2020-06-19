/* Reads a set of text lines and prints the longest. */

#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line size */

int get_line(char line[], int maxline); /* Don't need to set the size of the array here because it's set by the calling code in main */
void copy(char to[], char from[]); /* Void means the function doesn't return anything. It's leaving the part of the function prototype that normall declares the return-type "void", i.e. blank. */

main()
{
	int len; // Current line length
	int max; // Max len seen so far
	char line[MAXLINE]; // Current input line
	char longest[MAXLINE]; // Content of the longest line
	
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* there was a line (because the max of an empty line without even a newline character would be zero) */
		printf("%s", longest);
}

/* get_line: read a line into string ("char") s, return its length */
	/* NB nothing like python's builtin len() */
int get_line(char s[], int lim) /* "char s[]" is saying the parameter must be a list of strings/characters (?) */
{
	int c, i;
	
	for (i=0; i < lim-1 && (c = getchar()) != EOF && c !='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough to hold 'from' */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
