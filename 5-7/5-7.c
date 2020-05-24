#include <u.h>
#include <libc.h>
#include <stdio.h>
//#include <strings.h>

#define ALLOCSIZE 	10000
#define MAXLINES	5000
#define MAXLEN 		1000

int 	readlines(char *lineptr[], int nlines, char *buf, int *pos);
void 	writelines(char *lineptr[], int nlines);
int	getline(char *, int);
char*	alloc(int);
void	qsort2(char *lineptr[], int left, int right);

static char 	allocbuf[ALLOCSIZE];
static char 	*allocp = allocbuf;
char 	*lineptr[MAXLINES];


main(void)
{
	print("KR 5-7\n");
	int nlines, pos;
	int *pptr;
	static char buf[ALLOCSIZE];
	
	pos = 0; //position in buf init to 0
	pptr = &pos;
	if((nlines = readlines(lineptr, MAXLINES, buf, pptr)) >= 0) {
		qsort2(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		print("error: input too big to sort\n");
		return 1;
	}
}

int
readlines(char *lineptr[], int maxlines, char *buf, int *pos)
{
	int len, nlines;
	char *p, line[MAXLEN];

	print("read lines\n");
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		
		if (len + *(pos) >= ALLOCSIZE) /* check for overflow */
			return -1;
		p = buf + *(pos); 
		line[len - 1] = '\0';
		strcpy(p, line);
		lineptr[nlines++] = p;
		*(pos) += len;
		print("buf:\n%s", buf);
	}
	return nlines;
}

void
writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		print("%s\n", lineptr[i]);
}

void
qsort2(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int it, int j);
	
	print("qsort2\n");
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) > 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort2(v, left, last -1);
	qsort2(v, last + 1, right);
}

void
swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int
getline(char s[], int lim)
{
	int c, i;

	print("getline\n");
	for (i = 0; i < lim - 1 && (c = getchar()) != -1 && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

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
