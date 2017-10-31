#include <stdio.h>

int is_leap_year (int year_number)
{
	if(year_number < 1752) //can you just use year num like that?
	{
 		return -1;
	}
	else 
	{	
		return (((0 != (year_number % 100)) || (0 == (year_number % 400))) && (0 == (year_number %4 )));
	}
}

int calculate_days_in_month (int year_number, int month_number)
{
	if(year_number < 1752 || month_number < 0 || month_number > 11) 
	{
		return -1;
	}
	else if(month_number == 0 || month_number == 2 || month_number == 4 ||
		    month_number == 6 || month_number == 7 || month_number == 9 ||
	        month_number == 11)
	{
		return 31;
	}
	else if(month_number == 3 || month_number == 5 || month_number == 8 ||
	        month_number == 10)
	{
		return 30;
	}
	else
	{
		if(is_leap_year(year_number) == 0)
		{
			return 28;
		}
		else
		{
			return 29;
		}
	}	
}

int main()
{
	int a = 2013;
	int b = 11;
	int c = calculate_days_in_month (a,b); 
	printf("answer is %d\n",c); 
	return 0;
}

