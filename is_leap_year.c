
#include <stdio.h>

int main()
{
	int a=1800;
	int b =is_leap_year (a); //do i need this?
	printf("answer is %d",b);  //probly wrong
	return 0;
}


int is_leap_year (int year_number)
{
	int i=1;  //right place
	if(year_number < 1752) //can you just use year num like that?
	{
 	i=-1;
	}
	else if ((0 < (year_number % 100)) | (0 == (year_number % 400))) & (0 == (year_number %4 )//work?
	{	
	i=1;	
	}
	else
	{
	i=0;
	}
	return i;
}

