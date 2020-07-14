/* find pattern program that takes command line arguments including optional flags */

/* co-compile with getline.c */


#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	
	while (--argc > 0 && (*++argv)[0] == '-') /* while handling an argv element that started with '-', i.e. an optional flag */
		while (c = *++argv[0])
			switch (c) {
			case 'x':
				except = 1;
				break; /* break out of the inner while loop */
			case 'n':
				number = 1;
				break;
			default: /* user attempted to pass some other unrecognized flag */
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (my_getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}


/* getline might just be a part of stdio or string.h, compiler acted like that last time */
