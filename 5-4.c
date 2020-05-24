#include <u.h>
#include <libc.h>

int strend(char *s, char *t);

void
main(void)
{
	print("KR 5-4\n");
	char *s = "a string literal";
	char *t = "literal";
	int i = strend(s, t);
	print("i is: %d\n", i);
}

int
strend(char *s, char *t) 
{
	int i, j, c;

	i = strlen(s);
	j = strlen(t);
	for (c = 0; c < j; c++, j--) 
		if (*(s + (i - j)) != *(t + c))
			return -1;
	
	return  0;
}
