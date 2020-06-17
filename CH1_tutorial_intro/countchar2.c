#include <stdio.h>

/* Count characters in input; 2nd version 
	Uses double type instead of long int, also uses a for loop for 
	unrelated demo reasons*/
main()
{
	double nc;
	
	for (nc = 0; getchar() != EOF; ++nc)
		; /* on its own line to acknowledge it represents the empty
			body of this for loop */
	printf("%.0f\n", nc);
}
	

