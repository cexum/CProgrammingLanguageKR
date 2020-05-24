#include <u.h>
#include <libc.h>

void
main(int argc, char **argv)
{
	char *c;
	int a, b;

	print("a test app to extract command line args using ARGBEGIN\n");
	ARGBEGIN {
	case 'a':
		print("you passed in -a\n");
		a = atoi(ARGF());
		print("a = %d\n", a);
		break;
	case 'b':
		print("you passed in -b\n");
		b = atoi(ARGF());
		print("b = %d\n", b);
		break;
	case 'c':
		print("you passed in -c\n");
		//print("%s\n", c = ARGF());
		print("c = %s\n");
		break;
	default:
		print("invalid argument: %c\n", ARGC());
	} ARGEND
	print("I've finished parsing your args. Have a nice day.\n");
}
