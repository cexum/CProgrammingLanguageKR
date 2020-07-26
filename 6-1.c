#include <stdio.h>
#include <stdlib.h>

#define	 MAX	24

int getwd(char*, int);
int getch(void);
int isvalid(int c);
void ungetch(int);

char	buf[MAX];
int 	bufp = 0;

main()
{
	char wd[MAX];

	while (getwd2(wd, MAX) > 0)
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
	if (isalpha(c) || c == '_' || c =='#')
		return 1;
	return 0;
}

int validc(int c)
{
	if (isalnum(c) || c == '_')
		return 1;
	return 0;
}

int getwd2(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c == EOF) {
		*w = 0;
		return word[0];
	}
	while (!validstart(c)) {
		c = getch();
		if (c == EOF) {
		*w = 0;
		return word[0];
		}
	}
	*w++ = c;
	for ( ; --lim > 0; w++) 
		if (!validc((*w = getch()))) {
			ungetch(*w);
			break;
		}				
	*w = 0;
	return word[0];
}

int getwd(char *word, int lim)
{
	char *w = word;
	int c;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
