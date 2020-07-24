/* premise = a symbol table like what would be used by a compiler or macro processor to implement C's #define macros */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "simple_hash.h"
#include "table_lookup_structs.h"

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

struct nlist * // A function that returns a pointer to a "struct nlist" object
lookup(char *s)
/* lookup: look for s in hash table hashtab 
	
	Args:
		s (char *s): The key to look up. The "name", not the "defn".
*/
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next) /* using the linkages built into the nlist struct to 			increment to the next item. The nlist struct's "next" member is a pointer to the next entry in the chain. "The standard idiom for walking along a linked list". */
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL; /* not found */
}

struct nlist *
install(char *name, char *defn)
/* install: records a name and its replacement text in the hash table. Uses lookup to check whether name already present; if so, new definition defn will supersede the old one (updating the value defn for the key name) 
	
	Doesn't take a hashtable_name arg, because here it's hardcoded to operate on "hashtab" specifically.
*/
{
	struct nlist *np;
	unsigned hashval;
	
	if ((np = lookup(name)) == NULL) { /* not found */
		printf("name %s not found, installing it\n", name);
		np = (struct nlist *) malloc(sizeof(*np)); /* allocate space for the new entry */
		if (np == NULL || (np->name = strdup(name)) == NULL) /* np would equal NULL if malloc returned NULL due to 																		being unable to allocate any space */
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		printf("hashval is %u\n", hashval);
		hashtab[hashval] = np;
		printf("%p\n", np->next);
		printf("%p\n", hashtab[hashval]);
	} else /* name is already in the table */
		free((void *) np->defn); /* Free the memory that had been allocated to the name's definition */
	if ((np->defn = strdup(defn)) == NULL) /* One-linering--this will write defn as name's value before checking the if */
		return NULL;
	return np;
}

void
undef(char *name)
/* undef: remove a name and its definition from the table. */
{
	unsigned hashval;
	struct nlist *prev; /* nlist to be used for linking previous to what the deleted entry had linked to */
	struct nlist *t; /* removal target */
	
	prev = NULL;
	
	hashval = hash(name); /* return number that can be used for subscripting the hash table (hashtab is an array) */
	for (t = hashtab[hashval]; t != NULL; t = t->next) { /* traverse the hashtabl to find name, in order to get its 															"next" member */
		if (strcmp(name, t->name) == 0)
			break;
		prev = t; /* remember previous entry */
					/* It's not a doubly linked list--so needs some workarounding to reference previous rather than next */
	}
	if (t != NULL) { /* if target is in the table (?) */
		if (prev == NULL) /* checking if it's the first entry in the list */
			hashtab[hashval] = t->next;
		else /* if t isn't first entry */
			prev->next = t->next; /* update previous's "next" so that the modified LL functions properly */
		free((void *) t->name);
		free((void *) t->defn);
		free((void *) t); /* free the structure itself */
	}
	
}

void sandboxwrapper()
{
	struct nlist my_nlist;
	//my_nlist.name = "my nlist";
	//my_nlist.defn = "test nlist instance";
	//printf("%s\n", my_nlist.name);
	//printf("%p\n", hashtab[0]);
	//hashtab[0] = &my_nlist; /* this isn't properly hashing my_nlist into the table, this is circumventing the hash function and hard-coding hashtab[0] to be a specific thing */
	//printf("%p\n", hashtab[0]);
	//printf("%s\n", hashtab[0]->name);
	//printf("%p\n", hashtab[0]->next);
	//printf("%p\n", hashtab[1]); /* Doesn't print same address as hashtab[0]->next, because the hashtab entries aren't in order. That's why you need pointers to access them efficiently */
	
	/* will putting another item in the hashtab automatically deal with the next member of the first item? 
		...if you add them both with install function, then yes. */
	install("next entry", "a second entry into the table");
	/* to access this, need to use lookup */
	printf("%p\n", lookup("next entry"));
	printf("%s\n", lookup("next entry")->defn);
	printf("attempting to print 'next entry' pointer for nlist 'next entry':\n\t");
	printf("%p\n", (lookup("next entry")->next));
	
	/* overwriting the defn for the first entry: */
	//printf("original defn for the first entry:\n\t");
	//printf("%s\n", lookup("my nlist")->defn);
	install("my nlist", "new defn for the first entry");
	printf("%s\n", lookup("my nlist")->defn);
	printf("%s\n", hashtab[0]->defn); /* doesn't overwrite it because that first one wasn't hashed in normally using install. Lookup can't traverse the linked list properly because hashtab[0] hardcoding didn't put in a "next" member */
	install("my nlist", "third defn to overwrite with");
	printf("%s\n", lookup("my nlist")->defn);
	printf("----");
}

void undefsbxwrapper()
/* Quick manual testing for ex65 write undef function */
{
	/* install some entries in the table */
	
	install("first entry", "defn for first entry");
	install("second entry", "second entry's defn");
	install("thurddd entreeeiy", "muh garbage"); /* undesired entry to remove */
	install("fourth entry", "another normal entry");
	
	//printf("%s\n", lookup("second entry")->defn);
	//printf("%p\n", lookup("null entry")->defn);
	
	//hashtabprint();
	
	printf("%s\n", lookup("first entry")->name);
	printf("\t%s\n", lookup("first entry")->defn);
	printf("\tnext: %p\n", lookup("first entry")->next);
	
	printf("%s\n", lookup("second entry")->name);
	printf("\t%s\n", lookup("second entry")->defn);
	printf("\tnext: %p\n", lookup("second entry")->next);
	
	printf("%s\n", lookup("thurddd entreeeiy")->name);
	printf("\t%s\n", lookup("thurddd entreeeiy")->defn);
	printf("\tnext: %p\n", lookup("thurddd entreeeiy")->next);
	
	undef("thurddd entreeeiy");
	
	printf("---------\n");
	
	printf("%s\n", lookup("first entry")->name);
	printf("\t%s\n", lookup("first entry")->defn);
	printf("\tnext: %p\n", lookup("first entry")->next);
	printf("\tnext: %p\n", hashtab[hash("first entry")]);
	
	printf("%s\n", lookup("second entry")->name);
	printf("\t%s\n", lookup("second entry")->defn);
	printf("\tnext: %p\n", lookup("second entry")->next);
	
	/*printf("attempting to print nonexistent entry:\n");
	
	printf("%s\n", lookup("nonexistent entry")->name);
	printf("\t%s\n", lookup("nonexistent entry")->defn);
	printf("\tnext: %p\n", lookup("nonexistent entry")->next);*/
	
	printf("attempting to print third entry:\n");
	
	printf("%s\n", lookup("thurddd entreeeiy")->name); /* has seg fault because the name's gone */
	printf("\t%s\n", lookup("thurddd entreeeiy")->defn);
	printf("\tnext: %p\n", lookup("thurddd entreeeiy")->next);
	
}

int main()
{
	//sandboxwrapper();
	undefsbxwrapper();
	
	
	return 0;
}
