#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define SIZE 1000

int getline(char s[], int lim);
int htoi(char s[]);
void copy(char i[], char o[]);

int main(int argc, char **argv)
{	
	char *hex = "0xf0ff\0";
	htoi(hex);
	return 0;
}

int htoi(char s[]) 
{	
	/* copy input buffer to temp copy
	 * ensure that we don't have more than 8 nibbles
	 * because output is a 32 bit signed integer */
	int len = 0;
	signed long int value = 0;
	unsigned long int n = 0;	
	unsigned long int temp = 0;
	int c = 0;			
	int oset = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		puts("correct format detected");
		oset = 2;
	}
	else
		puts("missing header");	
		
	for (c = 0; s[c] != '\0'; ++c) {		
		if (c >= 8 + oset) {
			puts("hex string must be 8 nibbles or shorter");
			value = -1;
			return value;
		}
		len = c;
	}
	len -= oset;
	printf("calculated len of: %d\n", len);
	
	char hex[9] = {0};
	hex[8] = '\0';	
	
	for (c = 0; c < 8; ++c)			
		hex[c] = s[c + oset];	
	
	printf("hex string is: %s\n", hex);
	
	char t[9] = {0};
	t[8] = '\0';
	for (c = 0; c < 8; ++c) 
		t[c] = hex[c];
	
	printf("copy of string is: %s\n", t);
	for (c = 0; c < 8; ++c)
		hex[c] = 0;
	
	for (c = len; c >= 0; --c) 
		hex[len - c] = t[c];	
		
	printf("hex string reversed is: %s\n", hex);	
	puts ("calculate the integer val");	
	for (c = 0; c < 8 && hex[c] != '\0'; ++c) {
		if (hex[c] == 'f' || hex[c] =='F')
			n += (15 * (pow(16, c)));
		else if (hex[c] == 'e' || hex[c] =='E')
			n += (14 * (pow(16, c)));
		else if (hex[c] == 'd' || hex[c] =='D')
			n += (13 * (pow(16, c)));
		else if (hex[c] == 'c' || hex[c] =='C')
			n += (12 * (pow(16, c)));
		else if (hex[c] == 'b' || hex[c] =='B')
			n += (11 * (pow(16, c)));
		else if (hex[c] == 'a' || hex[c] =='A')
			n += (10 * (pow(16, c)));
		else if (hex[c] =='9')
			n += (9 * (pow(16, c)));
		else if (hex[c] =='8')
			n += (8 * (pow(16, c)));
		else if (hex[c] =='7')
			n += (7 * (pow(16, c)));
		else if (hex[c] =='6')
			n += (6 * (pow(16, c)));
		else if (hex[c] =='5')
			n += (5 * (pow(16, c)));
		else if (hex[c] =='4')
			n += (4 * (pow(16, c)));
		else if (hex[c] =='3')
			n += (3 * (pow(16, c)));
		else if (hex[c] =='2')
			n += (2 * (pow(16, c)));
		else if (hex[c] =='1')
			n += (1 * (pow(16, c)));
		else if (hex[c] =='0')
			n += (0 * (pow(16, c)));
		else {
			printf("found irregular value\nhex strings may only contain values 0 - F\n");
			value = -1;
			return value;
		}
	}
	
	printf("value of unsigned 32 bit int: %lu\n", n);
	value = (signed long int) n;
	printf("value of signed 32 bit int: %ld\n", value);
	
	return value;
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

void copy(char to[], char from[]) 
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
