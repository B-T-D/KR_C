

struct tnode { /* Struct for node in a binary tree */
	char *word; /* points to the text */
	int count; /* number of occurrences */
	struct tnode *left; /* recursion is ok here because pointing to the structure, instead of illegally including an 								actual instance of the structure in the structure's definition */
	struct tnode *right; /* Right child */
};
