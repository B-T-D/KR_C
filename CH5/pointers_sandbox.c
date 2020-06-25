/* misc. experimentation with pointers */

#include <stdio.h>
#include <assert.h>

#define intprint(expr) printf(#expr " = %d\n", expr)
//#define nprint(expr) printf(#expr " = %n\n", expr) // print a pointer
#define longprint(expr) printf(#expr " = %ld\n", expr)

int main()
{
	int x = 1, y = 2, z[10];
	int *ip; /* ip is a pointer to int 
					ip doesn't point to anything specific yet. 
					Trying to print it will cause segmentation fault.*/
	//nprint(ip);
	intprint(x);
	
	ip = &x; /* ip now points to x */
	intprint(*ip);
		// ^ This is type int, *ip is the thing ip points to, not the pointer
	//printf("%n\n", ip); 
	/* ^ This doesn't work to print any useful string repr, it prints nothing. And it sets *ip to zero, meaning it sets x = 0. */
	
	y = *ip; /* y is now 1--i.e. using the * operator to assign y the value of the thing that ip points to */
	intprint(y);
	
	printf("---setting *ip to zero---\n");
	*ip = 0; /* The thing ip points to is now 0. Meaning x is now zero. */
	intprint(x);
	intprint(y); /* But y is still 1. y was assigned with the value that *ip had at the time of that assignment statement */
	printf("-----\n");
	
	printf("---incrementing ip itself, not *ip---\n");
	ip += 1;
	intprint(*ip); /* Confirmed this **does** work to increment the memory address. It causes pointer to now point to y. Because +1 in memory from x is y. Because of the order of the assigmnent statements. */
	ip += 1; /* Incrementing it up one more ~byte makes it point to a garbage value. */
	intprint(*ip);
	ip -= 2;
	printf("------\n");
	
	*ip +=2;
	intprint(*ip);
	intprint(x);
	intprint(y); //why did y get set to 3 (i.e. the updated value of *ip), while x stayed at zero?
				/* because pointer += 1 does work as expected after all--it changed the memory address of the pointed-to thing. */
	
	ip = &z[0]; /* ip now points to the first element in int array z. */
	intprint(*ip); // prints the garbage value of z[0]
	
	/* Assigning a pointer equal to a different pointer will make that left-side pointer point to the same thing the right-side pointer did: */
	int *iq;
	iq = ip;
	iq = &y;
	assert(*iq == *ip);
	printf("assertion ok\n");
	
	
	/* what happens if a value is a long, and you shift the pointer by whatever += 1 shifts it by (presumably a byte, but maybe one 1+ byte memory object)? */
	
	long a = 99999;
	long *new_pointer = &a;
	longprint(a);
	longprint(*new_pointer);
		/* you can't use the unary * operator with a long (?)
		
	/* A short is two adjacent bytes. A short with a value that requires 2 bytes to hold, i.e. n >= 255, should therefore prove/disprove whether pointer += 1 increments one memory address or one contiguous object. */
	
	int b = 256; /* bytes should be 00000001 00000000 */
	int conspicuous_variable = 65535; /* to make bytes 11111111 11111111 easier to spot in 								viewing a string repr of the binary */
	int *pointer_b = &b;
	int c = 77777;
	
	printf("---Incrementing pointer b by 1---\n");
	intprint(*pointer_b);
	pointer_b += 1;
	intprint(*pointer_b); /* outputs 1...that's not the binary value of the first bit of the second byte of 256, right? If it were, would expect output to be zero if incrementing again. */
	pointer_b += 1;
	intprint(*pointer_b); /* Outputs 65535 -- the value of conspicuous_variable. So confirmed that pointer += 1 increments the address the pointer points to by one byte, not one 1+ byte memory object. */

	// If you increment again, twice, would the pointer point to itself?
	pointer_b +=1;
	//prediction: zero or some garbage value from the second byte of conspicuous_variable
	intprint(*pointer_b);
	printf("incrementing by one more, to presumably point pointer_b at itself\n");
	pointer_b +=1; // will this point the pointer at itself?
	intprint(*pointer_b); // outputs 0
	printf("incrementing one more, should point it at c = 77777\n");
	pointer_b +=1;
	intprint(*pointer_b); /* still zero, the pointer presumably occupies at least 2 bytes ("a pointer is a group of cells (often two or four)..." */
	printf("one more\n");
	pointer_b +=1;
	intprint(*pointer_b); // output = garbage
	printf("one more\n");
	pointer_b +=1;
	intprint(*pointer_b); /* output = 32765 or 32766... might be the first byte of 77777 with all its bits set to 1? Or could still be in the pointer if it's e.g. 4 bytes.*/
	printf("one more\n");
	pointer_b +=1;
	intprint(*pointer_b); // Garbage (?) -2146976192...max of a 32 bit signed int
	/* it changed upon recompiling (to approx -2^30.44). So it's a garbage value. */
	printf("one more\n");
	pointer_b +=1;
	intprint(*pointer_b);
	printf("------\n");
	
	
}
	
