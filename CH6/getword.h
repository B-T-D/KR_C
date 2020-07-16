#include <ctype.h>
#include "getch_ungetch.h"

int getword(char *word, int lim)
/* getword: get next word or character from input */
{
	int c, getch(void); /* this is one-linery of K&R--they're declaring an int then piggybacking that to declare the f							unction getch(void) that takes a void and returns an int */
	void ungetch(int);
	char *w = word;
	
	while (isspace(c = getch())) /* Ignore space characters in the input. For as long as character is a space, keep 										skiping to the next character */
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
