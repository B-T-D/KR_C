#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "count_keywords_structs.h"
#include "getch_ungetch.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0]) /* Number of keys is the size of the table divided by the size of each struct key object in the table. */

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main()
{
	int n;
	char word[MAXWORD];
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
/* binsearch: find word in table[0]...table[n-1]
	
	Args:
		word (char *): Target word to search for
		tab (struct key of size []): Sorted table in which to search for target word.
		n (int): Number of words in the table 
	
	Returns:
		(int): index position subscript at which the target appears, else -1 if not found
*/
{
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1; /* subscript of the last item in the table */
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0) /* strcmp returns < 0 if word is less than tab[mid].word, i.e. if 														word appears earlier than the initial middle word of the list */
			high = mid - 1;
		else if (cond > 0) /* using variable "cond" means only nead to call strcmp once */
			low = mid + 1;
		else /* if this was reached, then strcmp returned zero, i.e. cond == 0, i.e. target matches tab[mid].word */
			return mid;
	}
	return -1;
}

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

