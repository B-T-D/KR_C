struct nlist { /* table entry */
	struct nlist *next; /* Pointer to next entry in the chain--this is a linked list */
	char *name; /* defined name */
	char *defn; /* replacement text */
};

/* the table itself will exist as an array of pointers to "struct nlist" objects. It's an instance of a normal array so doesn't need its own struct defined. */

	/* static struct nlist *hashtab[HASHSIZE]; */
