#include <u.h>
#include <libc.h>

int strrindex(char *s, int t);

void
main(void)
{
	print("KR 4-1\n");
	char s[128] = { 'd', 'a', 't', 'a' };
	print("string literal is 'data'\n");
	print("right most occurence of 'z' is at index: %d\n", strrindex(s, 'z'));
	print("right most occurence of 'a' is at index: %d\n", strrindex(s, 'a'));
	print("right most occurence of 'd' is at index: %d\n", strrindex(s, 'd'));
}

int 
strrindex(char *s, int t)
{
	int in, c;
	
	in = -1;
	for (c = 0; c < strlen(s); c++) 
		if (t == s[c])
			in = c;
	return in;
}
