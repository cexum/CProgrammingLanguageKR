#include <stdio.h>
#include <stdlib.h>

#define RSIZE	1
#define WORD	16

typedef struct tnode Tnode;

struct tnode {
	char *word;
	int count;
	Tnode *left;
	Tnode *right;
};

int		scmp(char *, char *);
int 		badwd(char *);
int		sncmp(char *, char *, int);
char		*sndup(char *, int);
int		slen(char *);
void		sncpy(char *, char *, int);
Tnode		*talloc();
Tnode		*addntree(Tnode *, char *, int);
void		treeprint(Tnode *);
int		getwd(char *, int);
int		isalph(int);
int		isspc(int);
int		isdig(int);
int		getch(int);
void		ungetch();
int		atoin(char *);

char		buf[RSIZE];
char		*sp, *ep;
int 		fd;
char		wd[WORD];
Tnode		*root;
int		wlen;

int main(int argc, char **argv)
{
	if (!(fd = open(argv[1], 0))) {
		printf("err: open\n");
		return -1;
	}
	if (!argv[2])
		wlen = 6;
	else 
		wlen = atoin(argv[2]);
	while (getwd(wd, fd))
		if (!badwd(wd)) 
			root = addntree(root, wd, wlen);
	treeprint(root);
	return 0;
}

Tnode *addntree(Tnode *p, char *w, int len)
{
	int cond;
						
	if (!p) {
		p = talloc();
		p->word = sndup(w, len);
		p->count = 1;
		p->left = p->right = 0;
	} else if ((cond = sncmp(w, p->word, len)) == 0) 
		p->count++;
	else if (cond < 0) 
		p->left = addntree(p->left, w, len);
	else
		p->right = addntree(p->right, w, len);
	return p;
}

Tnode *talloc(void)
{
	return (Tnode*) malloc(sizeof(Tnode));	
}

void treeprint(Tnode *p)
{
	if (p) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);	
	}
}

int getwd(char *word, int fd)
{
	int c;
	char *w;

	for (w = word; !isalph(c = getch(fd)); ) 
		if (c <= 0)
			goto term;
		else if (c == '#') { 
			while ((c = getch(fd)) != ' ') 
				;
			c = getch(fd);
			if (c == '<')
				while ((c = getch(fd)) != '>')
					*w++ = c;
			else if (c == '\"')
				while ((c = getch(fd)) != '\"')
					*w++ = c;
			else {
				ungetch(c);
				while ((c = getch(fd)) != ' ')
					*w++ = c;
			}
			goto term;
		}	
		else if (c == '\"')
			while ((c = getch(fd)) != '\"')
				;
		else if (c == '/')
			if ((c = getch(fd)) == '/')
				while ((c = getch(fd)) != '\n')
					;
			else
				while ((c = getch(fd)) != '/')
					;			
	for ( ; isalph(c); c = getch(fd))
		*w++ = c;
	ungetch(c);
term:	*w = 0;
	return word[0];
}

void ungetch()
{
	sp--;
}

int getch(int fd)
{
	if (sp == ep) {
		if ((read(fd, buf, RSIZE)) <= 0) //reconsider
			return 0;		
	sp = buf;
	ep = sp + RSIZE;
	}
	return *sp++;
}

int isalph(int c)
{
	return (c == '_' || c >= 65 && c <= 90 || c >= 97 && c <= 122) ? 1 : 0;
}


void sncpy(char *src, char *dst, int len)
{
	int c;

	for (c = 0; c < len; c++)
		dst[c] = src[c];
}

char *sndup(char *s, int len)
{
	char *p;

	p = malloc(sizeof(len + 1));
	sncpy(s, p, len);
	return p;
}

int slen(char *s)
{
	int n;

	for (n = 0; s[n]; n++)
		;
	return n;
}

int scmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] == s2[c]; c++)
		if (s1[c] == 0)
			return 0;
	return s1[c] - s2[c];
}


int sncmp(char *s1, char *s2, int n)
{
	int c;

	for (c = 0; s1[c] == s2[c]; c++)
		if (c == n - 1)
			return 0;
		else if (s1[c] == 0)
			return 0;
	return s1[c] - s2[c];
}

int badwd(char *s)
{
	int c;
	static char *bad[] = {
		"auto", "break", "case", "char", "const",
		"continue", "default", "do", "double", "else",
		"enum", "extern", "float", "for", "goto",
		"if", "int", "long", "register", "return",
		"short", "signed", "sizeof", "static", 
		"struct", "switch", "typedef", "union",
		"unsigned", "void", "volatile", "while"
	};

	for (c = 0; bad[c]; c++)
		if (scmp(s, bad[c]) == 0)
			return 1;
	return 0;
}

int atoin(char *s)
{
	int i, n, sign;

	for (i = 0; isspc(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdig(s[i]); i++)
		n = n * 10 + (s[i] - '0');
	return sign * n;
}

int isspc(int c)
{
	return (c == ' ') ? 1 : 0;
}

int isdig(int c)
{
	return (c >= '0' && c <= '9') ? 1 : 0;
}
