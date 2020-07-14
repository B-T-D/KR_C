#include <stdio.h>

/* my_strcmp: array subscript version string comparison-- return <0 if s<t, 0 if s==t, >0 if s>t */
int my_strcmp_array(char *s, char *t)
{
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

int my_strcmp_pointer(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main()
{
	char *s = "first string";
	char *t = "second string longer than first";
	printf("%d\n", my_strcmp_array(s, t));
	printf("%d\n", my_strcmp_array("equal", "equal"));
	printf("%d\n", my_strcmp_pointer(s, t));
	printf("%d\n", my_strcmp_pointer("equal", "equal"));

}
