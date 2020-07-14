#include <stdio.h>

/* Arguments to main are passed at the command line, C already knows to treat them as argc (number of args) and argv (argument vector pointing to array of arg string, i.e. string reprs of the args themselves) */

/* echo command-line arguments, 1st version */
int main_1(int argc, char *argv[]) /* treats argv as an array of pointers */
{
	int i;
	
	for(i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
	return 0;
}

/* echo command-line arguments, 2nd version */
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	return 0;
}
