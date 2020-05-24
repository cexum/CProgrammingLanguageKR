#include <u.h>
#include <libc.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void
main(void)
{
	int doy, d, m, y, *pm, *pd;
	
	pm = &m;
	pd = &d;
	print("KR 5-8\n");
	print("test call of day_of_year\n");
	print("day = %d\n", (doy = day_of_year(2019, 4, 12)));
	print("test call of month_day\n");
	month_day(2019, 102, pm, pd);
	print("pm = %d, pd = %d\n", m, d);
}

int
day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		//day += daytab[leap][i];
		day += *(*(daytab + leap) + i);
	return day;
}

void
month_day(int year, int yearday, int *pmonth, int *pda)
{
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > *(*(daytab + leap) + i); i++) 
		yearday -= *(*(daytab + leap) + i);
	*pmonth = i;
	*pda = yearday;
}
