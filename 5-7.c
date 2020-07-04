#define NLINES	32
#define	LINE	256
#define	IN	1
#define BUF	512

int	ptc(int);
int 	pts(char*);
int 	slen(char*);
int 	getch(int);
int 	getln(int, char*, int);
int	readlines(int, char**, char*, int);
void	printlines(char**, int);
int	fopn(char*, int);
void	scp(char*,char*);

char	*lnp[NLINES];
char	buf[BUF];

test()
{
	static char buf[LINE];
	int fd;

	fd = open("f", 0);
	while (getln(fd, buf, LINE))
		pts(buf);
}

void main()
{
	int fd, n;
	
	fd = fopn("f", 0);
	n = readlines(fd, lnp, buf, NLINES);
	printlines(lnp, n);
}

void printlines(char **lineptr, int nlines)
{
	int c;

	for (c = 0; c < nlines; c++)
		pts(lineptr[c]);
}

void scp(char *in, char *out)
{
	int c;

	for (c = 0; in[c]; c++)
		out[c] = in[c];
}

int readlines(int fd, char **lineptr, char *arr, int maxlines)
{
	int nlines, len, i;
	static char buf[LINE];
	char *p;

	p = arr;
	nlines = 0;
	while ((len = getln(fd, buf, LINE)) && nlines < maxlines) {
		if (p + len > arr + BUF) 
			return nlines; // prevent overflow, but preserve valid lines
		scp(buf, p);    
		lineptr[nlines++] = p;
		p = p + len + 1;	
	}
	return nlines;
}

int fopn(char *p, int flag)
{
	return open(p, flag);
}

int getln(int fd, char *buf, int lim)
{
	int n, c;

	n = 0;
	while ((c = getch(fd)) && c != '\n' && c < lim - 2)
		buf[n++] = c;
	if (c == '\n')
		buf[n++] = '\n';
	buf[n] = 0;
	return n;
}

int ptc(int c)
{
	int b[1];

	b[0] = c;
	return write(1, b, 1);	
}

int pts(char *s)
{
	return write(1, s, slen(s));
}

int slen(char *s)
{
	int c;

	for (c = 0; s[c++]; )
		;
	return c;
}

int getch(int fd)
{
	static char *sp;
	static char *ep;
	static char in[IN];
	int c;
	
	if (sp == ep) {
		for (c = 0; c < IN; c++)
			in[c] = 0;
		sp = in;
		ep = sp + IN;
		read(fd, in, IN);	
	}
	return *(sp++);
}


