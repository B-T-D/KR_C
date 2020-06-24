/* Shell sort implementation and C. K&R brought it up to illustrate organization of nested loops.
(Shellsort is an optimization of insertion sort, still runs in O(n^2) worst case). */

#include <stdio.h>

/* shellsort: sort v, an array of ints, v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	
	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j] > v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

int main()
{
	int i;
	int v[100] = {1, 9, 2, 4, 6, 5, 8, 10, 3, 7}; /* for now manually shuffled with python then pasted back */
	
	printf("Original unsorted: ");
	for (i=0; i < 10; ++i)
		printf("%d, ", v[i]);
	printf("\n");
	
	printf("Expected: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,\n");
	
	printf("Actual: ");
	
	shellsort(v, 10); /* Book's example version has to be called with n = len(v), otherwise it won't sort the whole array */ 
	
	for (i=0; i < 10; ++i)
		printf("%d, ", v[i]);
	printf("\n");
}
	
	

