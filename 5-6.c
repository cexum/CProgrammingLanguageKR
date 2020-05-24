#include <u.h>
#include <libc.h>
#include <stdio.h>
#include <ctype.h>

int 	getline(char *, int);
void	reverse(char *);
int	atoi2(char *s);
int	strindex(char *, char*);
void 	itoa2(int, char*);	

void
main(void)
{	#define size 128
	char s[size] = { '1', '2', '3', '4' };
	int test;

	test = 4321;
	itoa2(test, s);
	printf("s: %s\n", s);
}

void 
itoa2(int n, char *s)
{
	int i, sign;

	if((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		*(s + i) = n % 10 + '0';
		i++;
	} while ((n /= 10) > 0);
	if (sign < 0) {
		*(s + i) = '-';
		i++;
	}
	reverse(s);
}

int
atoi2(char *s)
{
	int i, n, sign;
	
	for (i = 0; isspace(*(s + i)); i++)
		;
	sign = (*(s + i) == '-') ? -1: 1;
	if (*(s + i) == '+' || *(s + i) == '-')
		i++;
	for (n = 0; isdigit(*(s + i)); i++)
		n = 10 * n + (*(s + i) - '0');
	return sign * n;
}

int
strindex(char *s, char *t)
{
	int i,j,k;

	for (i = 0; *(s + i) != '\0'; i++) {
		for (j = i, k = 0; *(t + k) != '\0' && *(s + j) == *(t + k); j++, k++)
			;
		if (k > 0 && *(t + k) == '\0')
			return i;
	}
	return -1;
}

void
reverse(char *s)
{
	int i, c, t;
	
	i = 0;
	while (*(s + i) != 0)
		i++;

	c = 0;
	i -= 1;
	while (c < i) {
		t = *(s + c);
		*(s + c) = *(s + i);
		*(s + i) = t;
		i--;
		c++;
	}		
}

int
getline(char *s, int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != 0 && c != '\n'; i++)
		*s++ = c;
	if (c == '\n') {
		*s++;
	}
	*s = '\0';
	return i;
}
