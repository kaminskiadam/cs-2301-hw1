
#include <stdio.h>


int is_leap_year (int year_number)
{
	int i=1;  //right place
	if(year_number < 1900) //can you just use year num like that?
	{
 	i=-1;
	}
	else if (((0 != (year_number % 100)) || (0 == (year_number % 400))) && (0 == (year_number %4 )))s
	{	
	i=1;	
	}
	else
	{
	i=0;
	}
	return i;
}

int main()
{
	int a= 1900;
	int b = is_leap_year (a); //do i need this?
	printf("answer is %d\n",b);  //probly wrong
	return 0;
}

