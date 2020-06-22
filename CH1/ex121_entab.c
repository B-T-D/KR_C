/* Replaces spaces in the input with tab characters. */

#include <stdio.h>

#define NSPACES 4 /* Number of spaces per tab */

main()
{
	int c, nb, nt, pos;
	
	nb = 0; // Number of blanks needed
	nt; // Number of tabs needing replacement
	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ') {
			if (pos % NSPACES != 0)
				++nb;
			else {
				nb = 0; // Reset num blanks
				++nt; 
			}
		} else {
			for ( ; nt > 0; --nt)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else /* If it's a normal space, output a normal space */
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (NSPACES - (pos-1) % NSPACES) - 1;
		}
}
