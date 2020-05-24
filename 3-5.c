#include <u.h>
#include <libc.h>

void itob(int n, char *s, int b);
void itoh(int n, char *s);
void reverse(char *s);

int
main(int argc, char **args)
{
	print("KR 3-5\n");
	int val = 79;
	char hexs[128];
	itob(val, hexs, 8);
	print("%s\n", hexs);
	print("after function call\n");
	return 0;
}

void itob(int n, char *s, int b) 
{
	if (b > 16) {
		print("base must be <= 16\n");
		exits("base must be <= 16\n");
	}
	int r = 0;
	int quot = n;
	int c = 0;
	while (quot > 0) {
		r = quot % b;
		quot /= b;
		switch (r) {
			case 0:
				s[c] = '0';
				break;
			case 1:
				s[c] = '1';
				break;
			case 2:
				s[c] = '2';
				break;
			case 3: 
				s[c] = '3';
				break;
			case 4: 
				s[c] = '4';
				break;
			case 5: 
				s[c] = '5';
				break;
			case 6:
				s[c] = '6';
				break;
			case 7:
				s[c] = '7';
				break;
			case 8:
				s[c] = '8';
				break;
			case 9:
				s[c] = '9';
				break;
			case 10:
				s[c] = 'a';
				break;
			case 11:
				s[c] = 'b';
				break;
			case 12:
				s[c] = 'c';
				break;
			case 13:
				s[c] = 'd';
				break;
			case 14:
				s[c] = 'e';
				break;
			case 15:
				s[c] = 'f';
				break;
			default:
				break;
		}
		++c;
	}
	s[c] = '\0';
	reverse(s);
}
	
/* converts 32 bit ints to hex string */
void 
itoh(int n, char *s)
{
	int r = 0;
	int quot = n;
	int c = 0;
	while (quot > 0) {
		r = quot % 16;
		quot /= 16;
		print("right most digit: %d\n", r);
		switch (r) {
			case 0:
				s[c] = '0';
				break;
			case 1:
				s[c] = '1';
				break;
			case 2:
				s[c] = '2';
				break;
			case 3: 
				s[c] = '3';
				break;
			case 4: 
				s[c] = '4';
				break;
			case 5: 
				s[c] = '5';
				break;
			case 6:
				s[c] = '6';
				break;
			case 7:
				s[c] = '7';
				break;
			case 8:
				s[c] = '8';
				break;
			case 9:
				s[c] = '9';
				break;
			case 10:
				s[c] = 'a';
				break;
			case 11:
				s[c] = 'b';
				break;
			case 12:
				s[c] = 'c';
				break;
			case 13:
				s[c] = 'd';
				break;
			case 14:
				s[c] = 'e';
				break;
			case 15:
				s[c] = 'f';
				break;
			default:
				break;
		}
		++c;
	}
	s[c] = '\0';
	reverse(s);
}

void
reverse(char *s) 
{
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
