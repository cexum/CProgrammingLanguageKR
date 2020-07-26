#include <stdio.h>
#include <stdlib.h>

#define	 MAX	24

int getwd(char*, int);
int getch(void);
int validstart(int);
int isvalid(int);
void ungetch(int);

char	buf[MAX];
int 	bufp = 0;

main()
{
	char wd[MAX];

	while (getwd(wd, MAX) > 0)
		printf("word: %s\n", wd);
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

int validstart(int c)
{
	return (isalpha(c) || c == '_' || c == '#' || isspace(c)) ? 1 : 0;
}

int validc(int c)
{
	return (isalnum(c) || c == '_') ? 1 : 0;
}

int getwd(char *word, int lim)
{
	int c;
	char *w = word;

	while (!validstart((c = getch()))) 
		if (c == EOF)
			goto term;
	*w++ = c;
	for ( ; --lim > 0; w++) 
		if (!validc((*w = getch()))) {
			ungetch(*w);
			break;
		}				
term:	*w = 0;
	return word[0];
}

