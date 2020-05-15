#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy (char to[], char from[]);

int main(int argc, char **argv)
{
	int len; 
	
	char line[MAXLINE];
	
	
	
	while ((len = getline(line, MAXLINE)) > 0) {		
		if (len > 0)
			printf("len = %d\n", len);		
		else
			printf("there was no input buffer\n");
		
		if (len > 79) {
			printf("line > 80: %s\n", line);
			}
		}
	
	return 0;
}

int getline(char s[], int lim) 
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy (char to[], char from[]) 
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
