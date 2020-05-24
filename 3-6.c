#include <u.h>
#include <libc.h>
#define MAXNEG -2147483648

void reverse(char s[]);
int itoa(int n, int w, char s[]);

void 
main(void) 
{
	print("KR problem 3-6\n");
	
	int temp = 12;

	char buf[128];
	

	itoa(temp, 5, buf);
	print("%s\n", buf);

	exits(nil);
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int itoa(int n, int w, char s[]) 
{
	/* a moment of barbarism */
	if (n == MAXNEG) {
		maxneg:	
		s[0] = '-';
		s[1] = '2';
		s[2] = '1';
		s[3] = '4';
		s[4] = '7';
		s[5] = '4';
		s[6] = '8';
		s[7] = '3';
		s[8] = '6';
		s[9] = '4';
		s[10] = '8';
		s[11] = '\0';
		return 0;
	}
	
	int i, sign;
	int c, space;
	char copy[128];
	
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = 0;
	reverse(s);
	/* if < width, add padding */
	if (w > i) {
		space = w - i;
		for (c = 0; c < space; c++) {
			copy[c] = ' ';
		}
		for (c = 0; c < strlen(s); c++) {
			copy[c + space] = s[c];
		}	
	}
	for (c = 0; c < strlen(copy); c++) {
		s[c] = copy[c];
	}
	s[c + 1] = 0;
	return i;
}
