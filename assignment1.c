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
	if(dow >= 0)
	{
		return dow;
	}
	else
	{
		return (dow + 7);
	}
}

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
	int year;
	printf ("please enter a year\n");
	scanf("%d",&year);
	printf("\n");
	for(int i = 0; i < 12; i++)
	{
		switch(i)
		{
		case 0:
			printf("January\n");
			break;
		case 1:
			printf("February\n");
			break;
		case 2:
			printf("March\n");
			break;
		case 3:
			printf("April\n");
			break;
		case 4:
			printf("May\n");
			break;
		case 5:
			printf("June\n");
			break;
		case 6:
			printf("July\n");
			break;
		case 7:
			printf("August\n");
			break;
		case 8:
			printf("September\n");
			break;
		case 9:
			printf("October\n");
			break;
		case 10:
			printf("November\n");
			break;
		case 11:
			printf("December\n");
			break;
		default:
			printf("Invalid month!\n");
			break;
		}
		printf("Sun  Mon  Tue  Wed  Thu  Fri Sat\n");
		for(int b = 1; b < 31+ 1; b++) 
//calculate_days_in_month (year, i); b++)
		{
		printf("%d",b);
		}

		

	}
	return 0;
}

