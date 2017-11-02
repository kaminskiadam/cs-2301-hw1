
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

int input = 0;
int main(input)
{
	if (input != 0)
	{
		return is_leap_year (input);
	}
	else
	{
		printf("please enter a year"\n);
		scanf("%d",input);
		return is_leap_year (input);
	}

}

