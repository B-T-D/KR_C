/* Counts lines, "words", and characters. With "words" defined as simply 
any string of non-whitespace characters. */

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0; 
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') /* If it's a whitespace, we're outside of a word */
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
