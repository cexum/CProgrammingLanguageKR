#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);
int getint(int *pn);

void
main(void)
{
	print("KR 5-1\n");
	int i = 42;
	int *pn;
	
	pn = &i;
	getint(pn);
	print("value of i: %d\n", i);
}

int getch(void)
{
	print("inside getch\n");
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		print("ungetch: too many chars\n");
	else
		buf[bufp++] = c;
}

int getint(int *pn)
{
	int c, sign;
	print("trim input\n");
	while (isspace(c = getch()))
		;
	print("determine if digit\n");
	if (!isdigit(c) && c != 0 && c != '+' && c != '-') {
		print("is not a digit\n");
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	if (!isdigit(c)) {
		ungetch(c);
		print("no input following sign...\n");
		return -1;
	}
	print("store in pn\n");
	for (*pn = 0; isdigit(c); c = getch()) {
		print("inside for; pn is: %d\n", *pn);
		*pn = 10 * *pn + (c - '0');
		}
	*pn *= sign;
	if (c != 0)
		ungetch(c);
	return c;
}
