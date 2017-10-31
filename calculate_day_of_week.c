#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calculate_day_of_week (int day_of_month, int month_number, int year_number)
{
	// convert month format to the one required for the equation
	int m = ((month_number + 10) % 12) + 1;
	double c = (year_number - (year_number % 100));
	double y = (year_number % 100);
	int int_fun = 0;
	int_fun = (int) ((double) day_of_month + floor(2.6F * (double)m - 0.2)+y+floor(y/4)+floor(c/4)-2*c);
	int dow = (int_fun % 7);
	if(dow >= 0)
	{
		return dow;
	}
	else
	{
		return (dow + 7);
	}
}

int main(void)
{
	int a = calculate_day_of_week (2,10,2017);
	printf("day of week is %d\n",a);
	return 0;
}

