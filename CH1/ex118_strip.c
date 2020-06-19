/* Remove trailing blanks and tabs from each line, and delete entirely blank lines */

#include <stdio.h>
#define MAXLINE 1000 /* Needed? */
#define PRINTSIZE 20 /* Print lines with more characters than this */

int get_line(char line[], int maxline);
int remove_blanks(char s[]);

main()
{
	char line[MAXLINE];
	
	while(get_line(line, MAXLINE) > 0)
		if (remove_blanks(line) > 0) /* If there's any non-newline characters left after stripping the trailing tabs and spaces */
			printf("%s", line);
	return 0;
}

/* remove trailing blanks and tabs from character string s */
int remove_blanks (char s[])

{
	int i;
	
	i = 0;
	while (s[i] != '\n') /* find newline character, i.e. the end of the line */
		++i;
	--i; /* Move one character back from the end of the line */
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) /* If last character before the newline is one we want to strip, keep moving backward until no more trailing chars */
		--i;
	if (i >= 0) { /* If it's a nonblank line */
		++i;
		s[i] = '\n';  /* Add back newline character at end of line */
		++i;
		s[i] = '\0'; // Terminate the string
	}
	return i;
	
}

/* Don't need to return a character array object, mutate the one that was passed in, same as a python list */

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
