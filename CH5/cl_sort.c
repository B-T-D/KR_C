/* Sort lines inputted in terminal, and allow user to pass flag specifying whether to sort numerically instead of lexicographically */
	/* In initial sort_textlines, only lexicographic no numeric option, e.g. {4, 7, 5, 2, 12, 9} would sort to have 12 first */

#include <stdio.h>
#include <string.h>
#include "line_funcs.h" /* DIY my_getline and writelines from earlier in CH5 */
#include "compare_funcs.h" /* For DIY numcmp */

#define MAXLINES 5000
char *lineptr[MAXLINES]; /* array of pointers to text lines, with MAXLINES elements */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse); /* should be the same as first sort_textlines.c, this is 														just the output implementation not the comparison or the 												sort */


void myqsort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *)); /* This arg is a function whose own args are two unspecified 													pointers (i.e. type "void *") */
//int numcmp(char *, char *);
//int mystrcmp(char *, char *); /* stdlib strcmp takes arg of type const char * instead of just char * */


/* Sort input lines */
int main(int argc, char *argv[])
{
	int nlines; /* number of input lines to read */
	int numeric = 0; /* 1 for numeric sort instead of alpha */
	int reverse = 0; /* 1 to display output in reverse order */
	int ignore_case = 0; /* 1 to "fold" upper and lower case together, i.e. ignore case */
	int argchar;
	
	//if (argc > 1 && strcmp(argv[1], "-n") == 0) /* If user passed the "-n" flag... */
		//numeric = 1; /* ...set to numeric sort ("flag" at the CLI becomes a flag variable here in the 		program) */
	
	int (*fpcomp)(char *, char *) = &mystrcmp; /* pointer to the compare function to use */
	
	while (--argc > 0 && (*++argv)[0] == '-')
		while (argchar = *++argv[0])
			switch (argchar) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				ignore_case = 1;
				break;
			}
	
	if (numeric) {
		fpcomp = &numcmp; /* If numeric == 1, point fpcomp at numcmp function */
	} else {if (ignore_case)
		fpcomp = &strcmp_fold;
	}
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort((void **) lineptr, 0, nlines-1,
		(int (*)(void*,void*))(fpcomp)); /* Check for which compare function to pass can be done 																	right here in the qsort function call with this ternary 																expression */
		writelines(lineptr, nlines, reverse);
		printf("Exit with main returning 0\n");
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1; /* return non-zero to indicate a non-normal outcome */
	}
}

void swap(void *v[], int i, int j)
{
	void *temp; /* changed to void so it can deal with pointers of any type, prior version could only swap array elements that were pointers to character arrays */
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* qsort: sort v[left] ... v[right] into increasing order */
void myqsort(void *v[], int left, int right, int(*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int); /* What's the benefit of having this here? */
	
	if (left >= right) // Base case total elements < 2
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	myqsort(v, left, last-1, comp);
	myqsort(v, last+1, right, comp);
}

