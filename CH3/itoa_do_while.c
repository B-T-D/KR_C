/* Example of do-while being useful. 
"itoa" = "integer to ascii" */

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0 /* record sign */
		n = -n; /* make n positive */
	i = 0;
	do { // generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); // a separate function that reverses strings
	
	/* Do-while is convenient here because we want the while loop to run at least once no matter what, regardless of whether the controlling condition is true the first time it's checked. At least one character must be installed in the array s, even if n is zero. */
}

