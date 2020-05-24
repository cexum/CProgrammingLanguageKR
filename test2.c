#include <stdlib.h>
#include <stdio.h>

int
getch(void)
{
	return getchar();
}

void
main(void)
{
	printf("hello\n");
	int test = getchar();
}

