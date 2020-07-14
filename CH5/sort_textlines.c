#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* Max number of lines that can be sorted */

char *lineptr[MAXLINES]; /* array of pointers to textlines */

int readlines(char *lineptr[], int nlines); /* function prototypes */
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	int nlines; /* number of input lines read */
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 /* Max length of any single input line */
int my_getline(char s[], int);
char *alloc(int);

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
void writelines(char *lineptr[], int nlines)
{
	printf("-------/n"); //To make clearer where input ends and output begins in CLI
	while (nlines-- > 0) /* check it against zero then decrement it */
		printf("%s\n", *lineptr++); // print the current/old value before incrementing it
}

/* getline: read a line into s, return length. Section 1.9, p.29
	Returns:
		(int): length of the line read in
*/

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

/* qsort: sort array of character pointers into increasing order from lowest at v[left] to highest at v[right] */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) /* Base case--array contains 1 or zero elements, so is already sorted */
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i); /* increment last, then swap that new value rather than the old one */
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: swap the positions of two elements in an array */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
