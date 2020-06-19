/* Print a histogram of the lengths of words in the program's input. */

#include <stdio.h>

#define MAXHIST 15 /* Max length of histogram */
#define MAXWORD 11 /* Max length of a word */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

main()
{
	int c, i, nc, state;
	int length; /* length of each bar in the histogram */
	int maxvalue; /* maximum value for w1[] */
	int overflow; /* max number of overflow words */
	int w1[MAXWORD];
	
	state = OUT;
	nc = 0; /* number of chars in a word */
	overflow = 0; 
	for (i = 0; i < MAXWORD; ++i)
		w1[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT; /* If the character was a whitespace, we're now outside of a word until there's a non-whitespace char */
			if (nc > 0)
				if (nc < MAXWORD)
					++w1[nc];
				else
					++overflow; /* If word was longer than MAXWORD, increment the number of overflowing words */
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1; /* If state was not OUT and we hit a non-whitespace (i.e. char != the ws chars, then we're in a new word */
		} else
			++nc; /* inside a word */
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (w1[i] > maxvalue)
			maxvalue = w1[i]; /* update the max if something beat it */
	
	for (i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d : ", i, w1[i]);
		if (w1[i] > 0) {
			if ((length = w1[i] * MAXHIST / maxvalue) <= 0) /* Scales the size of the bar to the max word size in this set. One bar-piece character doesn't necessarily mean exactly one word with that length. */
				length = 1;
		} else
			length = 0;
		while (length > 0) {
			putchar('*');
			--length; /* len here serves as "number of bar-piece markers
			remaining to putchar for"--so decrement it each time a piece of a bar gets putchar-ed */
		}
		putchar('\n');
	}
	if (overflow > 0) /* If words overflowed, inform the user */
		printf("There are %d words with length >= %d\n", overflow, MAXWORD);
}
