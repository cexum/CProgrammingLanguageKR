#include <u.h>
#include <libc.h>

void itoa(int n, char s[]);
void reverse(char s[]);

void
main(void) 
{
	int i = -1234;
	char s[128];
	print("KR 4-12\n");
	
	itoa(i, s);
	print("string is: %s\n", s);
}

void 
itoa(int n, char s[])
{
	static int i;
	static int sign;
	
	/* determine sign on first iteration */
	if (i == 0) 
		if ((sign = n) < 0) 
			n = -n;
	s[i++] = n % 10 + '0';
	n /= 10;
	/* if there are more digits, recurse */
	if (n > 0) 
		itoa(n, s);
	else {
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}	
}

void reverse(char s[]) 
{
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

