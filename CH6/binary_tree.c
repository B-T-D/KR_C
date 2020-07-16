#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "binary_tree_structs.h"
#include "getword.h"

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
/* Word frequency count */
{
	struct tnode *root; /* pointer to the root node of the tree */
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *
talloc(void)
/* talloc: "tree allocator". Make a tnode in memory by returning a pointer to free space suitable for holding a tree node */
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode */* Alternate style function declaration K&R mention, with return type on its own line */
addtree(struct tnode *p, char *w)
/* Add a node with word w, at or below parent-node p */
{
	int cond;
	
	if (p == NULL) {  /* New word has arrived */
		p = talloc(); /* Make a new node--allocate space suitable for holding a tree node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++; /* Repeated word--strcmp returns 0 for match */
	else if (cond < 0) /* less-than word goes into left-child subtree */
		p->left = addtree(p->left, w);
	else /* greater-than word goes into right-child subtree */
		p->right = addtree(p->right, w);
	return p; /* Return the new subtree */
}

void
treeprint(struct tnode *p)
/* Print the binary tree in sorted order. At each node, prints the left subtree (all words less than this word), then the word itself, then the right subtree (all greater-than words). */
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}


/* Compiler conflicted with strdup defined in string.h. Just using that builtin one appeared to cause no problems. */


//char *
//strdup(char *s) /* maybe strdup was added to string.h since publication date? */
/* strdup: "string duplicator". Copy the string given by the argument into a safe place. */
//{
	//char *p;
	
	//p = (char *) malloc(strlen(s) +1); /* +1 for '\0' */
	//if (p != NULL) /* malloc returns NULL if no space is available */
		//strcpy(p, s);
	//return p;
//}
