#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy (char to[], char from[]);
void trim (char in[], int len);

int main(int argc, char **argv)
{
	int len; 
	
	char line[MAXLINE];
	
	
	
	while ((len = getline(line, MAXLINE)) > 0) {		
		if (len > 0) {
			printf("len pre trim = %d\n", len);		
			/* call trim here */
			trim(line, len);
			printf("len post trim = %d\n", len);		
			
			puts (line);
			}
		else
			printf("there was no input buffer\n");
		
				
		}
	
	return 0;
}

void trim(char in[], int len) 
{
	puts ("trim");
	int c;	
	/* empty string... */
	if (in[0] == '\n') {
		in[0] = '\0';
		}
	/*
	puts ("iterate through the string.. find null");
	for (c = 0; c <= len; c++) {
		if (in[c] != '\0') {
			printf ("found not null char: %c at index %d\n", in[c], c);
			}
		else
			printf ("found terminus char: %c at index %d\n", in[c], c);
		}
	
	printf ("len : %d\n c : %d\n", len, c);	
	
	for (c = (c - 1) ; c >= 0; --c) {
		printf ("%c\n", in[c]);
		}
	*/	
	/* start at len. if ' ' or '\n', replace with '\0' */
	for (c = len; c >= 0; --c) {
		if (in[c] == ' ' || in[c] == '\t') {			
			in[c] = '\0';
			}
		
		if (in[c] != ' ' && in[c] != '\t') {
			break;
			}			
		}	
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
