/* Quicksort implementation in C */

#include <stdio.h>
#include <assert.h>

/* qsort: sort array of integers v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j); //function prototype is allowed to be inside another function
	
	if (left >= right) /* base case--array with fewer than two element is already sorted */
		return;
	swap(v, left, (left + right) / 2 ); /* swap function is in its own .c source file, for demo of compiling from two separate source files--NB you don't need any kind of import statement, the .c source files aren't actually executed, they're compiled into the actual execution code. Compiler doesn't care what code's in what file so long as it has everything it needs. */
	/* $ gcc -o quicksort quicksort.c swap.c */
	last = left;
	for (i = left+1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last); /* put back partition element */
	qsort(v, left, last-1); /* Recursive case--recursively quicksort each partitioned half */
	qsort(v, last+1, right);
}

int main()
{	
	int i;
	int nums[5] = {5, 2, 3, 4, 1};
	int expected_nums[5] = {1, 2, 3, 4, 5};

	qsort(nums, 0, 4); /* Args for left and right need to be indices of first and last elements in the list, for this simple version */

	for (i = 0; i <= 4; ++i)
		assert(nums[i] == expected_nums[i]);
	printf("Assertions ok\n");
}
