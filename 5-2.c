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
double getfloat(double *dptr);

void
main(void)
{
	print("KR 5-2\n");
	double d = 0;
	double  *pn;
	
	pn = &d;
	getfloat(pn);
	print("value of d: %f\n", d);
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

double
getfloat(double *dptr)
{
	double power;
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != 0 && c != '+' && c!= '-') {
		print("not a digit...\n");
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
	for (*dptr = 0; isdigit(c); c = getch()) {
		*dptr = 10.0 * *dptr + (c - '0');
	}
	if (c == '.') {
		c = getch();
	}
	/* handle cases where there are no numbers after '.'? */
	for (power = 1.0; isdigit(c); c = getch()) {
		*dptr = 10.0 * *dptr + (c - '0');
		power *= 10.0;
	}
	*dptr = sign * *dptr / power;
	return c;
}
