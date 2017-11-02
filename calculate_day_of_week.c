#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calculate_day_of_week (int day_of_month, int month_number, int year_number)
{
	// convert month format to the one required for the equation
	int m = ((month_number + 10) % 12) + 1;
	int c = (year_number - (year_number % 100)) / 100;
	int y = (year_number % 100);
	if(month_number <= 1)
	{
		y--;
	}
	int int_fun = (int) (day_of_month 
				+ (int)floor((2.60001F * (double)m) - 0.2F)
				+ y
				+ (int)floor((double)y / 4.F)
				+ (int)floor((double)c / 4.F)
				- (2 * c));
	int dow = (int_fun % 7);

	printf("day_of_month = %d\n", day_of_month);
	printf("month_number = %d\n", month_number);
	printf("year_number = %d\n", year_number);
	printf("m = %d\n", m);
	printf("c = %d\n", c);
	printf("y = %d\n", y);
	printf("term 2 with inserted 12= %d\n", (int)floor((2.60001F * 12.0F) - 0.2F));
	printf("floor(31.2-.2)= %d\n", (int)floor((31.2F) - 0.2F));
	printf("12*2.6 = %F\n", (12.0F*2.60001F));
	printf("2.6m = %F\n", (2.60001F * (double)m));
	if(dow >= 0)
	{
		return dow;
	}
	else
	{
		return (dow + 7);
	}
}

int main(int argc, char* argv[])
{
	//int a = calculate_day_of_week (2,0,2017);
	int a = calculate_day_of_week (atoi(argv[1]),atoi(argv[2]),2017);
	printf("day of week is %d\n",a);
	return 0;
}

//MAKE IT SO IT DOESNT WORK IF INPUT IS OFF

