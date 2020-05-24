#include <u.h>
#include <stdio.h>
#include <libc.h>
#define MAXLINE 1000

int
getline(char s[], int lim)
{
	int c, i;
	
	while (--lim > 0 && (c = getchar()) > 0 && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

