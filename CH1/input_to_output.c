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
	int c;
	
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
