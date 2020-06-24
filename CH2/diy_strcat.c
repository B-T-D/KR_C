/* DIY version of standard lib strcat function */

#include <stdio.h>
#include <string.h>


/* my_strcat: concatenate string t to end of string s; s must be big enough */
void my_strcat(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0') // Find end of s
		i++;
	while ((s[i++] = t[j++]) != '\0') // copy t
		; /* the while loop definition does everything that needs to be done, nothing else left needing to be done in the body of the loop */
}

int main()
{
	char first_string[100] = "first part";
	char second_string[100] = "; second part";
	printf("%s\n", first_string);
	printf("%ld\n", strlen(first_string));
	my_strcat(first_string, second_string);
	printf("%s\n", first_string);
	printf("%ld\n", strlen(first_string));
	return 0;
}
