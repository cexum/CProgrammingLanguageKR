#include <u.h>
#include <libc.h>

void strcatptr(char *s, char *t);
void strcatptr2(char *s, char *t);
void strcatptr3(char *, char *);
void strcatptr4(char *, char *);

void
main(void)
{
	print("KR 5-3\n");
	char source[128] = { 'd', 'a', 't', 'a' };
	char dest[128] = { 'm', 'o', 'r', 'e' };
	char *s, *t;

	s = source;
	t = dest;
	strcatptr4(s,t);
	print("result of concat on new line:\n%s\n", s);
}

/* 
void
strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}
*/

void 
strcatptr(char *s, char *t)
{
	int i, j;

	i = j = 0;
	while (*(s + i) != '\0')
		i++;

	while (*(t + j) != '\0') {
		*(s + i) = *(t + j);
		i++;
		j++;
	}
}

void 
strcatptr2(char *s, char *t)
{
	while (*s != '\0')
		s++;
	while (*t != '\0') {
		*s = *t;
		s++;
		t++;
	}
}

void 
strcatptr3(char *s, char *t)
{
	while (*s)
		s++;
	while (*t)
		*s++ = *t++;
}

void 
strcatptr4(char *s, char *t)
{
	while (*s++)
		;
	while (*s++ = *t++)
		;
}
