#include <stdio.h>
#include <string.h>

/* squeeze: delete all occurrences of character c from string s */
void squeeze(char s[], int c)
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++) /* doesn't matter here whether ++ is before i or after */
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0'; /* Shorten the string for each c removed */
}

int main()
{
	char s[100] = "azbzczdzezfzgzh";
	
	printf("%s\n", s);
	printf("%ld\n", strlen(s));
	squeeze(s, 'z');
	printf("%s\n", s);
	printf("%ld\n", strlen(s));
}
