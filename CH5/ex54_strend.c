/* Write the function strend(s, t) which returns 1 if the string t occurs at the end of the string s, else zero */

#include <stdio.h>
#include <assert.h>
#include <string.h>



int strend(char *s, char *t)
{
	char *bs = s; /* Separate pointers to store the beginning of each string, before we increment the main s and t pointers to point at other characters */
	char *bt = t; /* "bt" for "beginning of t"... */
	
	for ( ; *s; s++) /* Increment pointer s til it points at the last character in the string */
		; /* Nothing else to do. Merely executing 's++' changes what pointer s points at. */
	
	for ( ; *t; t++) /* Same for t. */
		;
	
	/* Now have accessed the end of each string, so can iterate over the characters in reverse order similar to what python does with negative index numbers (string[-1]...) */
	for ( ; *s == *t; s--, t--) /* '*s == *t' -- continue for as long as the thing that s points to equals thing t points to, i.e. the chars match */
		if (t == bt || s == bs) /* if we reach the beginning of either string (t could be longer than s) */
			break;
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}

void simple_testcase() {
	
	char *s = "strend";
	char *t = "end";
	assert(strend(s, t) == 1);
	printf("Assert ok -- strend('end', 'strend') should return 1 because 'strend' ends with 'end'.\n");
	
	t = "foo";
	assert(strend(s, "foo") == 0);
	printf("Assert ok -- strend('foo', 'strend') returns 0.\n");

}

int main() {
	
	simple_testcase();
}




int strend_scratchwork (char *s, char *t) {

	
	int i;
	
	printf("'s' is %s -- the full string 'char *s'\n", s);
	printf("'*s' is %c -- the thing that pointer s points to is the first character of the string 'char *s'\n", *s);
	
	/* 
	s += 1;
	printf("after incrementing the pointer s by 1, *s (the thing s points to) should now be the second character of the string:\n\t%c\n", *s);
	*/
	
	/* Incrementing s until it points to the last character in the string: */
	for ( ; *s; s++)
		printf("s now points to %c\n", *s);
	
	printf("s[-1] is %c\n", s[-1]);
		
	for (i = 0; i < 5; i++)
		printf("%d\n", i);
		
	for (i = 4; i >= 0; i--)
		printf("%d\n", i);
	
	for (i = strlen(t) - 1; i >= 0; i--) {
		printf("i is %d\n", i);
		printf("%c\n", s[i]);
		if (s[i] != t[i])
			return 0;
		}
	return 1;
	
	
	/* 
	for (*s == '\0'; *s == *t; s--, t--)
		printf("*s is %c\n", *s);
		return 1;
	return 0;
	*/

}
