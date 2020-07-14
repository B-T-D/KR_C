/* Sandboxing for unit testing approaches with C */

#include "compare_funcs.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXDOTS 1000

int passed_tests = 0;
int failed_tests = 0;
char dots_string[MAXDOTS]; /* python unittest module style string of dots updated in real time as tests pass */

void passed() /* What to do when a test passes */
{
	passed_tests++;
	printf("."); /*print a dot without a newline, so they'll all be on the same line imitating python unittest module */
}

void test_numcmp_simple() /* Wrapper function to run asserts on quickstart simple case for the numcmp function */
{
	char *s1 = "12";
	char *s2 = "9";
	
	assert(numcmp(s1, s2) == 1); /* should return 1 for s1=12 > s2=9 */
	printf("%d\n", numcmp(s1, s2) == 1); /* Would want to write a different, generalized assert type function that doesn't terminate execution on assert failure, but rather logs something like python unittest module. E.g. pass it expected and actual, it returns 1 if actual == expected else 0. Or pass actual, expected, and operator to generalize beyond just testing for equality. */ 
	passed();
	
	assert(numcmp(s2, s1) == -1); /* should return -1 if first number less than second */
	passed();
	
	assert(numcmp("4", "4") == 0); /* should return 0 if numbers equal */
	passed();
	
}




int main()
{
	test_numcmp_simple();
	printf("\nPassed %d tests\n", passed_tests);
	return 0;

}

