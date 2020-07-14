#include <stdio.h>
#include "alloc.c"

#define MAXLEN 1000 /* Max length of any single input line */

int my_getline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* readlines: read input lines
	Returns:
		(int): Total number of input lines
 */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
	//int reverse = 1; /* for testing */
	//printf("%s\n", lineptr[0]); /* since lineptr is an array of string pointers, it should be subscriptable */
	//printf("%s\n", lineptr[1]);
	//printf("Can you print the last line by trying to subscript array to lineptr[nlines]?\n");
	//printf("\t%s\n", lineptr[nlines - 1]);
	printf("-------\n");
	if (reverse)
		printf("reverse was true\n");
	printf("-------\n"); //To make clearer where input ends and output begins in CLI
	
	if (reverse) {
		while (nlines-- > 0) /* redundant code (two while loops) to avoid checking the if--which will 									never change here--every time through the while loop */
			printf("%s\n", lineptr[nlines]);
	} else
		while (nlines-- > 0)
			printf("%s\n", *lineptr++);
	
	//while (nlines-- > 0)
		//if (reverse) { /* This is checking the if every single time through the while loop--can't be efficient, right? In terms of time complexity, an entire separate while loop would be better, even if there's a more elegant way, right? This wouldn't change the big O but it would change an n to a 2n.*/
			//printf("%s\n", lineptr[nlines]);			
		//} else
			//printf("%s\n", *lineptr++); // print the current/old value before incrementing it
}
