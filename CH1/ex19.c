/* Copy program's input to its output, replacing each string of one or 
more blanks by a single blank */

#include <stdio.h>

#define	BLANK ' ' /* To avoid having to correctly type same single-space
string multiple times */
main()
{
	int c;
	c = getchar();
	while (c != EOF) {
		if (c != BLANK)
			putchar(c);
		if (c == BLANK) {
			c = getchar(); /* Iterate over same c so that can resume 
			at correct position once a non-space is hit */
			while (c == BLANK)
				c = getchar(); /* skip to next char til that char's not a 										space */
			putchar(BLANK); /* Putchar one single space no matter how many
			times c had to be advanced to the next char */
			putchar(c); /* this char isn't a blank anymore, so need to 
			put it before continuing, otherwise it'd be skipped. */
			}
		c = getchar();
	}
}
