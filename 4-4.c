#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <stdio.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getops(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void printtop(void);
void clear(void);
void swap(void);
void duplicate(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

main()
{
	print("reverse Polish calculator\n");
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getops(s)) != 0) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case 'D':
			duplicate();
			break;
		case 'S':
			swap();
			break;
		case 'C':
			clear();
			break;
		case 'P':
			printtop();
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
				print("error: division by zero\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				print("error: division by zero\n");
		case '\n':
			print("\t%.8g\n", pop());
			break;
		default:
			print("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


void
push(double f)
{
	print("push\n");
	if (sp < MAXVAL) {
		val[sp++] = f;
		print("pushed %f to stack\n", f);
	}
	else
		print("error: stack full\n");
}

double
pop(void)
{
	if (sp > 0) {
		print("popped: %f\n", (val[(sp - 1)]));
		return val[--sp];
	}
	else {
		print("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand */
int
getops(char s[])
{
	print("getop\n");
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		print("!isdigit: %d\n", c);
		return c;
	}
	i = 0;
	if (isdigit(c)) {
		print("isdigit: %d\n", c);
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != 0)
		ungetch(c);
	return NUMBER;
}

/* get a (possibly pushed back) character */
int 
getch(void)
{
	print("getch\n");
	/*
	print("returning: %d\n", ((bufp > 0) ? buf[--bufp] : getchar()));
	*/
	return (bufp > 0) ? buf[--bufp] : getchar();
} 

/* push character back on input */
void
ungetch(int c)
{
	print("ungetch\n");
	if (bufp >= BUFSIZE)
		print("ungetch: too many characters\n");
	else 
		buf[bufp++] = c;
}

void printtop()
{
	if (sp > 0)
		print("top value of stack is: %f\n", val[(sp - 1)]);
	else
		print("nothing to print: stack is empty\n");

}

void clear()
{
	int c;
	if (sp > 0) {
		for (int c = 0; c <= sp; c++)
			val[c] = 0;
		sp = 0;
		print("cleared stack\n");
	}		
	else
		print("nothing to clear: stack is already empty\n");
}

void swap()
{
	double temp;
	if (sp > 1) {
		temp = val[(sp - 2)];
		val[(sp - 2)] = val[(sp -1)];
		val[(sp - 1)] = temp;
		
	}
	else
		print("cannot swap\n");
}

void duplicate()
{
	print("duplicate\n");
	double temp;
	if (sp > 0) {
		temp = val[(sp - 1)];
		push(temp);
	}
	else 
		print("stack is empty: cannot duplicate\n");
}

