#include <u.h>
#include <libc.h>
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
void ungets(char[]);

void
main(void)
{
	printf("KR 4-5\n");
	char input[BUFSIZE] = { 'i', 'n', 'p', 'u', 't' };
	
	print("before push\n");
	print("buf: %s\n", buf);
	ungets(input);
	print("after push\n");
	print("buf: %s\n", buf);
}

int 
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void 
ungetch(int c)
{
	if (bufp >= BUFSIZE)
		print("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void 
ungets(char s[])
{
	int c, i;

	i = 0;
	while (s[i] != 0) {
		c = s[i++];
		ungetch(c);
	}
}

