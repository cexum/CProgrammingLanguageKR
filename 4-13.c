#include <u.h>
#include <libc.h>

void reverse(char s[]);

void
main(void)
{
	print("KR 4-13\n");
	char s[128] = { 'a', 'b', 'c', 'd', 'e' };
	reverse(s);
	print("reversed string: %s\n", s);
	reverse(s);
	print("reverse again: %s\n", s);
}

void reverse(char s[]) 
{
	static int c;
	int temp;
	
	if (c < (strlen(s) / 2)) {
		temp = s[c];
		s[c] = s[(strlen(s) - 1) - c];
		s[(strlen(s) - 1) - c] = temp;
		c++;
		reverse(s);
	}
	else {
		s[(strlen(s))] = '\0';
		c = 0;
	}	
}
