#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char in[], int len);

int main(int argc, char **argv)
{
	int len; 
	
	char line[MAXLINE];
	
	
	
	while ((len = getline(line, MAXLINE)) > 0) {		
		if (len > 0) {
				
			reverse(line, len);
			puts (line);
			}
		else
			printf("there was no input buffer\n");
		
				
		}
	
	return 0;
}

void reverse(char in[], int len) {
	int c;
	char temp[len];
	int end = len - 1;
	
	/* copy to a working buffer */
	for (c = 0; c < len; c++) {
		temp[c] = in[c];
		}
	/* reverse the string */
	for ( ; c >= 0; --c) {
		in[end - c] = temp[c];
		}
	/* re insert the '\n' */
	in[len] = '\n';	
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


