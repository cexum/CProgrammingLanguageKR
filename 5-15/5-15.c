#include <u.h>
#include <libc.h>
#include <stdio.h>

#define MAXLINES 	5000
#define ALLOCSIZE	10000
#define MAXLEN		1000

void	usage(void);
int	readlines(char **, int);
void	writelines(char **, int);
void	qsort2(void *lineptr[], int, int, int (*comp)(void*, void*));
int	numcmp(char *, char *);	
int	getline(char *, int);
char*	alloc(int);
int	cmp(void *, void *);

char		*lineptr[MAXLINES];
static char	allocbuf[ALLOCSIZE];
static char	*allocp = allocbuf; /* does this violate p9 style? */
int 	numeric, r, f;

int
main(int argc, char **argv)
{
	int nlines;

	print("KR 5-15\n");
	ARGBEGIN {
	case 'f':
		print("fold option\n");
		f = 1;
		break;		
	case 'r':
		print("print reverse option\n");
		r = 1;
		break;
	case 'n':
		print("sort numeric option\n");
		numeric = 1;
		break;
	default:
		usage();
		break;
	} ARGEND
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
		qsort(lineptr, nlines, sizeof(char *), (int (*)(void *, void *))cmp);
	else 
		print("input too big to sort\n");
	writelines(lineptr, nlines);
	return 0;
}

void
qsort2(void *v[], int left, int right, int (*comp)(void *, void*))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last , i);
	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);
}

void
swap(void *v[], int i, int j)
{
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


int
cmp(void *s1, void *s2)
{
	if (numeric)
		return numcmp(*(char **)s1, *(char **)s2);
	else if (f)
		return cistrcmp(*(char **)s1, *(char **)s2);
	else
		return strcmp(*(char **)s1, *(char **)s2);
}

int
numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int
readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) 
		if (nlines >= maxlines || (p = alloc(len)) == nil) 
			return -1;
		 else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void
writelines(char *lineptr[], int nlines)
{
	int i;

	if (r == 1)
		for (i = nlines; i >= 0; i--)
			print("%s\n", lineptr[i]);
	else	 
		for (i = 0; i < nlines; i++)
			print("%s\n", lineptr[i]);
}

int
getline(char s[], int lim)
{
	int c, i;

	print("input line\n");
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
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else {
		print("alloc returns 0 (not enough room)\n");
		return 0;
	}
}

void
usage(void)
{
	fprint(2, "usage: %s \n", argv0);
	exits("usage");
}
