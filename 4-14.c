#include <u.h>
#include <libc.h>

#define swap(t,x,y) { t = x; x = y; y = t; }


main()
{
	print("KR 4-14\n");
	int t, y, x;
	y = 3;
	x = 7;
	print("initial values of:\nx: %d\ny: %d\n", x, y);
	swap(t, x, y);
	print("after swap:\nx: %d\ny: %d\n", x, y);
	return 0;
}

