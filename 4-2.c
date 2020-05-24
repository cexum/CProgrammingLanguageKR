#include <u.h>
#include <libc.h>
#include <ctype.h>

double atof(char s[]);

void
main(void)
{
	print("KR 4-2\n");
	char s[128] = { '1', '2', '3', '.', '4', '5', 'e', '-', '6' };
	double val = atof(s);
	print("val = %f\n", val);
}

double
atof(char s[])
{
	double val, power, exp, temp;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* omit ' ' */
		;
	sign = (s[i] == '-') ? -1 : 1;	
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	temp = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		/* determine sign of exponent */
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		/* determine value of exponent */
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10.0 * exp + (s[i] - '0');
		/* shift decimal */	
		for (i = 0; i < exp; i++) {
			if (sign == 1)
				temp *= 10;
			else 
				temp /= 10;
		} 
	}
	return temp;
}
