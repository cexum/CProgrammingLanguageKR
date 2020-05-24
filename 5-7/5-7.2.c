#include <u.h>
#include <libc.h>
#include <stdio.h>
//#include <strings.h>
#include <bio.h>

#define ALLOCSIZE 	10000
#define MAXLINES	5000
#define MAXLEN 		1000

int 	readlines(uchar *lineptr[], int nlines, uchar *buf, int *pos);
void 	writelines(uchar *lineptr[], int nlines);
int	getline(uchar *, int);
char*	alloc(int);
void	qsort2(uchar *lineptr[], int left, int right);
void	ustrcpy(uchar*, uchar*);
int 	ustrcmp(uchar*, uchar*);

static char 	allocbuf[ALLOCSIZE];
static char 	*allocp = allocbuf;
uchar 	*lineptr[MAXLINES];
Biobufhdr bp;
Biobuf out;

main(void)
{
	print("KR 5-7\n");
	int nlines, pos;
	int *pptr;
	static uchar buf[ALLOCSIZE];
	
	Binit(&out, 1, OWRITE);
	Binits(&bp, 0, OREAD, buf, sizeof buf);
	pos = 0; //position in buf init to 0
	pptr = &pos;
	if((nlines = readlines(lineptr, MAXLINES, buf, pptr)) >= 0) {
		//qsort2(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		print("error: input too big to sort\n");
		return 1;
	}
}

int
readlines(uchar *lineptr[], int maxlines, uchar *buf, int *pos)
{
	int len, nlines;
	uchar *p, line[MAXLEN];

	print("read lines\n");
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		print("len = %d\n", len);
		if (len + *(pos) >= ALLOCSIZE) /* check for overflow */
			return -1;
		p = buf + *(pos); 
		line[len - 1] = '\0';
		ustrcpy(p, line);
		lineptr[nlines++] = p;
		*(pos) += len;
		//print("buf:\n%s", buf);
	}
	print("i have read all lines, and am proceeding with flow\n");
	return nlines;
}

void
writelines(uchar *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++) {
		Bprint(&out, "%s", lineptr[i]);
		//print("%s\n", lineptr[i]);
	}
}

void
qsort2(uchar *v[], int left, int right)
{
	int i, last;
	void swap(uchar *v[], int it, int j);
	
	print("qsort2\n");
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (ustrcmp(v[i], v[left]) > 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort2(v, left, last -1);
	qsort2(v, last + 1, right);
}

void
swap(uchar *v[], int i, int j)
{
	uchar *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int
getline(uchar s[], int lim)
{
	int c, i;
	//Biobufhdr bp;

	print("getline\n");
	
	
	for (i = 0; i < lim - 1 && (c = Bgetc(&bp)) != Beof && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	print("i = %d\n", i);
	print("unmodified line: %s", s);
	return i;
}

/*
char* 
alloc(int n)
{
	print("allocbuf + ALLOCSIZE - allocp = %d\n", (allocbuf + ALLOCSIZE - allocp));
	print("n = %d\n", n);
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else {
		print("alloc returns 0 (not enough room)\n");
		return 0;
	}
}
*/

void
ustrcpy(uchar *s1, uchar *s2)
{
	while (*s1++ = *s2++)
		;
}

int
ustrcmp(uchar *s, uchar *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
