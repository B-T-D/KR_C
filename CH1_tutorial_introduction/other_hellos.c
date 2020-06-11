#include <stdio.h>

/* \a is supposed to be "audible alert"...apparently it won't output
an actual sound on Ubuntu https://stackoverflow.com/questions/3456138/this-program-sounds-the-bell */

main()
{
	printf("hello, world \n\a");
}
