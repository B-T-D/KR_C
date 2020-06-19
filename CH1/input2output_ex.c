/* Pseudocode:
	read a character
	while (character isn't end-of-file indicator):
		output the character just read
		read a character
*/

#include <stdio.h>

/* Copy input to output */
main()
{
	int c; /* c needs to be an int because it needs a type big enough
	to contain both the character input, and the EOF value.*/
	
	while ((c = getchar()) != EOF)
		printf("Value of EOF is %d\n", EOF);
		printf("%3d\n", c != EOF);
		putchar(c);
}
