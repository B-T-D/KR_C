#include <stdio.h>
#include <assert.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* Storate for alloc */
static char *allocp = allocbuf; /* next free position -- this initial declaration starts the character pointer pointing at the beginning of allocbuf. This will be whatever was the next free position at the moment the program began execution (the first code that affects memory is the declaration of allocbuf to be an array of size ALLOCSIZE, i.e. nothing else happens in the program prior to setting the beginning of allocbuf). */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* if it fits. allocbuf means the starting mem location of allocbuf */
		allocp += n; /* advance the delimiter of the allocated space by n */
		return allocp - n; /* return the old value of allocp before this new allocation to n was made */
	} else /* if there's not enough remaining space in allocbuf, return zero */
		return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
		printf("afree if condition evaluated True\n");
		allocp = p;
		
}



