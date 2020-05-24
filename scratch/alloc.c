#include<u.h>
#include<libc.h>

static char 	arr[10000];
char		*lineptr[5];

void
main(void)
{
	char *p;
	char *line = "literal\n";
	char *line2 = "another literal\n";
	int len;
	
	print("alloc.c\n");
	len = strlen(line);
	p = arr;
	strcpy(p, line);
	p = arr + len;
	strcpy(p, line2);
	print("%s", arr);
	lineptr[0] = p;
	lineptr[1] = "hard coded literal\n";
	print("%s%s", lineptr[0], lineptr[1]);
}
