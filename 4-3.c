#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getops(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

main()
{
	printf("reverse Polish calculator\n");
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getops(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: division by zero\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: division by zero\n");
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


void
push(double f)
{
	printf("push\n");
	if (sp < MAXVAL) {
		val[sp++] = f;
		printf("pushed %f to stack\n", f);
	}
	else
		printf("error: stack full\n");
}

double
pop(void)
{
	if (sp > 0) {
		printf("popped: %f\n", (val[(sp - 1)]));
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand */
int
getops(char s[])
{
	printf("getop\n");
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		printf("!isdigit: %d\n", c);
		return c;
	}
	i = 0;
	if (isdigit(c)) {
		printf("isdigit: %d\n", c);
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

/* get a (possibly pushed back) character */
int 
getch(void)
{
	printf("getch\n");
	
	return (bufp > 0) ? buf[--bufp] : getchar();
} 

/* push character back on input */
void
ungetch(int c)
{
	printf("ungetch\n");
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else 
		buf[bufp++] = c;
}
