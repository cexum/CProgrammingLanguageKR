#include <u.h>
#include <libc.h>

void	strcpyn(char *, char *, int n);

void
main(void)
{
	char *source;
	char dest[128];
	int n;

	print("KR 5-5\n");
	source = "data";
	n = 3;
	strcpyn(source,dest, n);
	print("after strcpyn\nsource: %s\ndest: %s\n", source, dest);
}

void 
strcpyn(char *s, char *t, int n)
{
	int c;

	c = 0;
	while ((*t++ = *s++) && c++ < (n - 1)) 
		;	
}
