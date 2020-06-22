/* Replaces tabs in the input with a fixed number of spaces. */

#include <stdio.h>

#define NSPACES 4 /* Number of spaces with which to replace each tab */ 

main()
{
	int c, nb, pos;
	
	nb = 0; /* Number of blanks needed */
	pos = 1; // Position of character in that line-string
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nb = NSPACES - (pos - 1) % NSPACES;
			while (nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		} else if (c == '\n') {
			putchar(c);
			pos = 1; // Reset pos if on a new line
		} else { // normal characters
			putchar(c);
			++pos;
		}
	}
}
