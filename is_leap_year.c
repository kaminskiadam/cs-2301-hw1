
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

int main()
{
	int a= 1600;
	int b = is_leap_year (a); 
	printf("answer is %d\n",b); 
	return 0;
}

