#include <stdio.h>

#define SIZE 1000

int getline(char s[], int lim);

int main(int argc, char **argv)
{
	char line[SIZE] = {0};
	getline(line, SIZE);
	puts(line);
	return 0;
}

int getline(char s[], int lim) 
{	
	int c, i;
	
	for (i = 0; i < lim - 1; ++i)
		s[i] = 0;	
		
	for (i = 0; i < lim - 1; ++i) {
		c = getchar();
		if (c == EOF)
			break;
			
		if (c != '\n')
			s[i] = c;			
	}
		
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
