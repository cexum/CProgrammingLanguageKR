#include <u.h>
#include <libc.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
	char buf[128] = {0};

	print("get an argv != null, put next arg into string\n");

	while (--argc > 0) {
		strcat(buf, *++argv);
		if (argc == 1)
			break;
		strcat(buf, " ");
	}
	print("%s\n", buf);
	return 0;
}
