#include <stdio.h>
#include <stdlib.h>

#define	 MAX	24

int getwd(char*, int);
int getch(void);
int isspace(int);
int isalph(int);
void ungetch(int);

char	buf[MAX];
int 	bufp = 0;

main()
{
	char wd[MAX];

	while (getwd(wd, MAX) > 0)
		printf("word: %s\n", wd);
}

int isalph(int c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return 1;
	return 0;
}

int isspace(int c)
{
	return (c == ' ') ? 1 : 0;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= MAX)
		printf("ungetch: overflow\n");
	else 
		buf[bufp++] = c;
}

int getwd(char *word, int lim)
{
	int c;
	char *w = word;

	while (!isalph(c = getch()))
		if (c < 0) { //not detecting EOF??
			*w = 0;
			return word[0];
		}
	while (isalph(c)) {
		*w++ = c;
		c = getch();
	}
	ungetch(c);
	*w = 0;
	return word[0];
}
