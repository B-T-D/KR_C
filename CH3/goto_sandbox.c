/* Quick misc. familiarization with goto syntax */

#include <stdio.h>

int main()
{
	int n = 0;
	
	first_if: // label will be ignored in normal execution--it's not a condition to check
		if (n <= 0) {
			printf("n was <= zero\n");
			goto my_label;
			}
		else
			printf("Didn't goto anything out of the first_if block\n");
			goto end_execution; /* manually skip to the end of the code to prevent infinitely looping from the goto first_if line */
	
	my_label: // this is a "label", the thing that a goto redirects execution to
		printf("goto sent to my_label\n");
	
	n = 1;
	
	if (n > 0)
		goto first_if;
		
	end_execution:
		printf("goto sent to end of the program\n");
		
	/* Easy to write a total-mess program -- "the infinitely-abuseable goto statement" */
}
		
