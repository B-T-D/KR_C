/* Check a C program for rudimentary syntax errors including
	- Unbalanced parentheses, brackets, or braces
*/

#include <stdio.h>

int paren, brack, brace;

void in_quote(int c);
void in_comment(void);
void search(int c);

main()
{
	int c;
	extern int paren, brack, brace; /* Using a global variable--these were defined at the start outside of any function */
	
	while ((c = getchar()) != EOF) { 
	/* First, ignore comments or chars in quotation marks */
		if (c == '/') { /* If first char is a slash, then if the next char is asterisk, it's a comment-start */
			if ((c = getchar()) == '*')
				in_comment(); /* inside multiline comment */
			else
				search(c);
		} else if (c == '\'' || c == '"')
			in_quote(c); // Inside quote
		else
			search(c);
		}
		
	if (brace < 0) { /* Output messages when errors found */
		printf("Unbalanced braces (missing an opening)\n");
		brace = 0; 
	} else if (brack < 0) {
		printf("Unbalanced square brackets (missing an opening)\n");
		brack = 0;
	} else if (paren < 0) {
		printf("Unbalanced parentheses (missing an opening)\n");
		paren = 0;
	}
	
	if (brace > 0)  /* Output messages for too many paren/brack/brace */
		printf("Unbalanced braces (missing a closing)\n");
	if (brack > 0)
		printf("Unbalanced square brackets (missing a closing)\n");
	if (paren > 0)
		printf("Unbalanced parentheses(missing a closing)\n");
	
	if (paren == brack == brace == 0)
		printf("No imbalance errors found.\nOrdering mistakes still possible, i.e. ')(' vs. '()'.\n");
	
}

/* search: search for rudimentary syntax errors */
void search(int c) // It's not really a "search", more like a parse
{
	extern int paren, brack, brace;
	
	if (c == '(')
		++paren;
	else if (c == ')')
		--paren;
	else if (c == '[')
		++brack;
	else if (c == ']')
		--brack;
	else if (c == '{')
		++brace;
	else if (c == '}')
		--brace;
}

/* in_comment: inside of a valid comment */
void in_comment(void) /* Only handles multiline comments that have a end end syntax character that's different from just the end of the comment's line */
{
	int c, d;
	
	c = getchar(); /* previous character */
	d = getchar(); /* current character, i.e. getchar() returns the next character after c */
	while (c != '*' || d != '/') { /* Find end of the comment */
		c = d;
		d = getchar();
	}
}

/* in_quote: inside quote */
void in_quote(int c)
{
	int d;
	
	while((d = getchar()) != c) /* If in_quote() was called, it was because c was either a single or a double quotation mark character. Main calls in_quote(c) only for that value of c. Seems like not the most clean and modular way to do it */
		if (d == '\\') /* I.e. a single backslash, this line of code is escaping the backslash, to identify escape char in the input */
			getchar(); /* If the character was escaped, go to the next character without doing anything else */
}
