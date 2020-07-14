#include <stdlib.h>

/* numcmp: compare strings s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	v1 = atof(s1); // ascii to float
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int mystrcmp(char *s, char *t) /* Return <0 if s<t, 0 if s==t, >0 if s>t */
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int strcmp_fold(char *s, char *t) /* version of strcmp that ignores case */

/* see also ctype.h builtin toupper(int c) and tolower(int c) functions */
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	if ((65 <= *s && *s <= 90) && (97 <= *t && *t <= 122)) { /* If s is upper and t is lower, add 32 to s such that if they're same letter, the return will be zero, i.e. code for matching characters */
		printf("%c is upper and %c is lower\n", *s, *t);
		return (*s + 32) - *t;
	} else if ((65 <= *t && *t <= 90) && (97 <= *s && *s <= 122)) {
		printf("%c is lower and %c is upper\n", *s, *t);
		return *s - (*t + 32);
	} else
		return *s - *t;
}
