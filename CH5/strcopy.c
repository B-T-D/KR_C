#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* my_strcpy: copy t to s; array subscript version */
void my_strcpya(char *s, char *t) /*args are same for either function. Pointers to the arrays of characters. */
{
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0') /* one-liner to simultaneously set t[i] to s[i]. */
		i++; /* all that's left to do in the body of the loop is increment i. Since the code that says to copy each char is already in the while condition */
		
		/* less compact version would be 
			while (t[i] != '\0')
				s[i] = t[i];
				i++;
		*/
}

/* my_strcpyp: copy t to s, pointer version 1 */
void my_strcpyp(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* my_strcpyp_2: copy t to s, pointer version 2 (more code-compact) */
void my_strcpyp_2(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		; // Nothing left to do in loop body
}

/* my_strcpyp_3: copy t to s, further compacted v3. Comparison to '\0' is redundant, since the question is only whether the expression is zero */
void my_strcpyp_3(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

int main()
{ /* something in my syntax is wrong here wrt the blank copy-into string--compiling fine then causing seg fault. Might be that s1 needs to be blank but with enough allocated memory to hold t1? */
	char *t1 = "first test string";
	char *s1 = "this string is longer than the first test string"; // blank (this is same as = "\0", both would have len=0)
	//realloc(s1, 1000); /* Shouldn't need to get into realloc just to copy a string. Problem here is most likely very basic syntax thing */
	printf("%ld\n", strlen(t1));
	printf("%ld\n", strlen(s1));
	
	//s1 = strcpy(s1, t1); // this way also doesn't work
	printf("%s\n", strcpy(s1, t1)); /* stdlib strcpy doesn't work either. Problem's not in the functions. */
	//printf("%s\n", strcpy("", "test")); /* Also doesn't work--but its compiler warning supports that this is a memory allocation sizing issue */
	printf("stdlib strcpy ok");
	
	printf("%s\n", s1);
	printf("%s\n", t1);
	printf("test\n");
	my_strcpyp_2(s1, t1);
	printf("my_strcpya function call ok\n");
	printf("%s\n", s1);

}
