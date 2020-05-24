#include <u.h>
#include <libc.h>
#include <bio.h>

#define	MAXWORD	100
#define BUFSIZE	100

// typedef struct
struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0,
};


// prototype
void usage(void);
int getword(char *, int);
int binsearch(char * struct key *, int);
// global
char buf[BUFSIZE];
int bufp = 0;
void
main(int argc, char **argv)
{
	ARGBEGIN {
	default:
		usage();
	} ARGEND
	if (argc != 0)
		usage();
	print("6-1\n");
	
}

void
usage(void)
{
	fprint(2, "usage: %s\n", argv0);
	exits("usage");
}

int
binsearch(char *word, struct key tab[], int n)
{
	int cond, low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int
getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

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

int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
