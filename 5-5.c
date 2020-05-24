#include <u.h>
#include <libc.h>

void	strcpyn(char *, char *, int n);
void	strcatn(char *, char *, int n);
int	strcmpn(char *, char *, int n);

void
main(void)
{
	char source[128] = { 'd', 'a', 't', 'a' };
	char dest[128] = { 'd', 'a', 't', 'a' };
	int n;

	print("KR 5-5\n");
	n = 3;
	strcmpn(source,dest, n);
	print("n is: %d\n", n);
}

int 
strcmpn(char *s, char *t, int n)
{
	int i;

	for ( ; *s == *t; s++, t++) {
		print("s is: %c\nt is: %c\n", *s, *t);
		if (!(*s))
			return 0;
	}
	return *s - *t;
}

void
strcatn(char *s, char *t, int n)
{
	int c;

	while (*s)
		s++;
	c = 0;
	while (*t && c++ < n)
		*s++ = *t++;
}

void 
strcpyn(char *s, char *t, int n)
{
	int c;

	c = 0;
	while ((*t++ = *s++) && c++ < (n - 1)) 
		;	
}
