#include <u.h>
#include <libc.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
	int c;

	print("argc: %d\n", argc);
	while (--argc > 0)
		print("%s%s", *++argv, (argc > 1) ? " " : "");
		c = 0;
		while(*(argv + c) != '\0')
			print(argv[c]);
	print("\n");
	return 0;
}
