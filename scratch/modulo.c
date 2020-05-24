#include <u.h>
#include <libc.h>

main()
{
	print("testing mod operator");
	double temp;
	temp = fmod(23.3, 7.1);
	print("temp: %f\n", temp);
	return 0;
}
