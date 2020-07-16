/* Pointer version */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "count_keywords_structs.h"
#include "getword.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0]) /* Number of keys is the size of the table divided by the size of each struct key object in the table. */

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* count C keywords */
int main()
{
	char word[MAXWORD];
	struct key *p; /* a pointer, "p", to a struct key object */
	
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
				///////
	for (p = keytab; p < keytab +NKEYS; p++) /* increment p to point at the next item in the table, until p has 														iterated through all items in the table. */
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
/* binsearch: find word in table[0]...table[n-1]
	
	Args:
		word (char *): Target word to search for
		tab (struct key *): Pointer to first "struct key" object in sorted table in which to search for target word.
		n (int): Number of words in the table 
	
	Returns:
		(struct key *): pointer to struct key object that matched the search target, else NULL if not found
*/
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n]; /* now point to just past the end of the table */
	struct key *mid;
	
	while (low < high) {
		mid = low + (high-low) / 2; /* can't do (low+high) / 2 anymore, because adding two pointers is illegal--but 										subtraction is allowed. (high-low) gives the number of elements, i.e. a number 											rather than a pointer. That number can then be legally added to the pointer "low". 										*/
		if ((cond = strcmp(word, mid->word)) < 0) /* strcmp returns < 0 if word is less than tab[mid].word, i.e. if 														word appears earlier than the initial middle word of the list */
			high = mid;
		else if (cond > 0) /* using variable "cond" means only nead to call strcmp once */
			low = mid + 1;
		else /* if this was reached, then strcmp returned zero, i.e. cond == 0, i.e. target matches tab[mid].word */
			return mid;
	}
	return NULL;
}



