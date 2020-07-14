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


int main()
{	
	char *allocpointer;
	char *allocpointer_2;
	int n = 10;
	int m = 5;
	printf("ok\n");
	printf("initial print of allocbuf:\n\t%s\n", allocbuf);
	printf("printing a call to *alloc() function with n = %d:\n", n);
	allocpointer = alloc(n);
	printf("\t%p\n", allocpointer); /* %p to print as pointer. Hex repr of the memory address. */

	/* get a second pointer for a new n. This should return a higher (subsequent) memory address, and therefore evaluate to > the first allocpointer. */
	allocpointer_2 = alloc(m);
	printf("allocpointer_2 address:\n\t%p\n", allocpointer_2);
	assert(allocpointer_2 - allocpointer == n);
	printf("Assertion ok:\n\tallocpointer_2 - allocpointer == n\n");
	assert(allocpointer < allocpointer_2);
	printf("Assertion ok:\n\tallocpointer < allocpointer_2\n");
	/* after calling afree() with allocpointer_2 as arg, allocpointer_2 should equal allocpointer. Because both allocp pointers should now be pointing to address corresponding to n being the last used piece of allocbuf, m not being allocated any more */
	afree(allocpointer_2);
	printf("allocpointer address:\n\t%p\n", allocpointer);
	printf("allocpointer_2 address:\n\t%p\n", allocpointer_2);
	printf("allocp address ('real' one as opposed to the copies i've made in main):\n\t%p\n", allocp);
	printf("calling afree(allocp) i.e. on the 'real one':\n");
	afree(allocp);
	printf("\t%p\n", allocp); /* not working to prove that afree is deallocating the memory; moving on for now */
	return 0;
}

