/* Count blanks, tabs, and newlines */

/* Primitive control flow because haven't used anything other than "if"
yet */

#include <stdio.h>

main()
{
	int c, ws;
	
	ws = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++ws;
		if (c == ' ')
			++ws;
		if (c == '\t')
			++ws;
	};
	printf("%d\n", ws);
}
