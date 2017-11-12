/*
 ============================================================================
 Name        : assignment3.c
 Author      : 
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALPHABETICAL_GRADES 4

/**
 * Calculates the final grades for each student based on their grades and the percent weight of the grade.
 * Note that this function does not return a value.  The final grades are stored in final_grades.
 * This variable is passed by pointer value and can be seen by the calling part of the program.
 * The variable name in the calling program may be different, but it will be the same memory locations.
 * @param number_of_students  The number of students
 * @param number_of_grades The number of grades for each student
 * @param grades The 2-dimensional array of grades (pretend this is a 2d-array)
 * @param percentages A one-dimensional array for the percent that each grade should be worth
 * 		  This corresponds to the columns of the grades array
 * @param final_grades A one-dimensional array to hold the values for the final grades
 */
void calculate_final_grades(int number_of_students, int number_of_grades, int *grades[], int *percentages, int *final_grades)
{
	// IMPLEMENT (10 points)
}

/**
 * Calculates the mean of the grades
 * @param number_of_students The number of students
 * @param grades The grades (one-dimensional array)
 * @return Returns the mean of the grades, -1 if there are no students
 */
double calculate_mean(int number_of_students, int *grades)
{
	double mean = -1;
	double total = 0;
	for(int i = 0; i < number_of_students; i++)
	{
			total = total + grades[i];
	}
	if(number_of_students <= 0)
	{
		return -1;
	}
	else
	{
		mean = total / number_of_students;
		return mean;
	}
}
/////////////////////////////seems to work/////////////////

/**
 * Calculates the standard deviation of the grades
 * @param number_of_students The number of students
 * @param grades The grades (one-dimensional array)
 * @return Returns the standard deviation, -1 if there are no students
 */
double calculate_standard_deviation(int number_of_students, int *grades)
{
	double standard_deviation = -1.0;
	// IMPLEMENT (10 points)
	//dont forget divide by 0
	double x = calculate_mean(number_of_students,grades);
	double sum_total = 0.0;
	for(int i = 0 ; i < number_of_students ; i++)
	{
		double n = 0;
		n = (grades[i] - x);
		sum_total = pow(n,2.0) + sum_total;
	}
	standard_deviation = sqrt((1.0 / number_of_students) * sum_total);
    return standard_deviation;
}

/**
 * Calculates the counts for each letter grade.  Stores the counts in grade_counts.
 * Note that this function does not return a value.  The counts are stored in grade_counts.
 * This variable is passed by pointer value and can be seen by the calling part of the program.
 * The variable name in the calling program may be different, but it will be the same memory locations.
 * @param number_of_students
 * @param alphabetic_grades A one-dimensional array of alphabetical grades
 * @param grade_counts A count for each letter. Index 0 = 'A', Index 1 = 'B',  Index 2 = 'C', Index 3 = 'N'
 */
void get_grade_counts(int number_of_students, char *alphabetic_grades, int *grade_counts)
{
	for(int i = 0; i < ALPHABETICAL_GRADES ; i++)
	{
		grade_counts[i] = 0;
	}
	for(int i = 0 ; i < number_of_students ; i++)
	{
		if(alphabetic_grades[i] == 'A')
		{
			grade_counts[0] = grade_counts[0] + 1;
		}
		else if(alphabetic_grades[i] == 'B')
		{
			grade_counts[1] = grade_counts[1] + 1;
		}
		else if(alphabetic_grades[i] == 'C')
		{
			grade_counts[2] = grade_counts[2] + 1;
		}
		else
		{
			grade_counts[3] = grade_counts[3] + 1;
		}
	}
}

/**
 * Calculates the alphabetic grade based on the numeric grade.
 * Note that this function does not return a value.  The alphabetical grades are stored in alphabetical_grades.
 * This variable is passed by pointer value and can be seen by the calling part of the program.
 * The variable name in the calling program may be different, but it will be the same memory locations.
 * @param number_of_students  The number of students
 * @param numeric_grades A one-dimensional array containing the numeric grade for each student
 * @param alphabetic_grades A one-dimensional array containing the alphabetic grade for each student
 */
void calculate_letter_grades(int number_of_students, int *numeric_grades, char *alphabetic_grades)
{
	for(int i = 0; i < number_of_students ; i++)
	{
		char output = 'a';
		if(numeric_grades[i] >= 90)
		{
			output = 'A';
		}
		else if(numeric_grades[i] >= 80)
		{
			output = 'B';
		}
		else if(numeric_grades[i] >= 70)
		{
			output = 'C';
		}
		else
		{
			output = 'N';
		}
		alphabetic_grades[i] = output;
	}
}
//////////////make sure grade ranges are correct

/**
 * For testing, printing out just the initial grades
 * @param number_of_students
 * @param number_of_grades
 * @param grades
 */
void print_grades(int number_of_students, int number_of_grades, int *grades[])
{
	for(int i=0; i<number_of_students; i++)
	{
		for(int j=0; j<number_of_grades; j++)
		{
			printf("%d,", grades[i][j]);
		}
		printf("\n");
	}
}

/**
 * For testing, printing out final grades
 * @param number_of_students
 * @param final_grades
 */
void print_final_grades(int number_of_students, int *final_grades)
{
	for(int i=0; i<number_of_students; i++)
	{
		printf("final grades %d\n", final_grades[i]);
	}
}

/**
 * Generates a random gradebook based on the hyperparameters
 * Done for you
 * @param number_of_students
 * @param number_of_grades
 * @param grades
 * @param percentages
 * @param seed
 */
void generate_gradebook(int number_of_students, int number_of_grades, int *grades[], int *percentages, int seed)
{

	for(int i=0; i<number_of_students; i++)
	{
		for(int j=0; j<number_of_grades; j++)
		{
			int random_grade = rand() % 100;
			grades[i][j] = random_grade;
		}
	}

	int raw_percents[number_of_grades];
	double percent_sum = 0.0;
	for(int i=0; i<number_of_grades; i++)
	{
		raw_percents[i] = rand() % 100;
		percent_sum = percent_sum + raw_percents[i];
	}

	int normalized_percent_sum = 0.0;
	for(int i=0; i<number_of_grades-1; i++)
	{
		double normalized_percent = 100.0 * raw_percents[i] / percent_sum;
		raw_percents[i] = floor(normalized_percent);
		normalized_percent_sum = normalized_percent_sum + raw_percents[i];
	}

	raw_percents[number_of_grades-1] = 100 - normalized_percent_sum;

	for(int i=0; i<number_of_grades; i++)
	{
		percentages[i] = raw_percents[i];
	}
}

int main(int argc, const char *argv[])
{
	int seed = 7;
	srand(seed);

	// change these two variables as desired for testing
	int const number_of_students = 3;
	int const number_of_grades = 5;

	int *grades[number_of_students];  // the 2d array (students X grades)
	int final_grades[number_of_students];  // the 1d array of final grades for each student
	char final_alphabetical_grades[number_of_students];  // the 1d array of final alphabetical grades
	int percentages[number_of_grades]; // weighting percent for each grade (each column of grades)
	int grade_counts[ALPHABETICAL_GRADES]; // count of each alphabetical grade

	// need to allocate memory
	for(int i=0; i<number_of_students; i++)
	{
		grades[i] = malloc(sizeof(int) * number_of_grades);
	}

	// generates a random gradebook
	generate_gradebook(number_of_students, number_of_grades, grades, percentages, seed);

	print_grades(number_of_students, number_of_grades, grades);

	calculate_final_grades(number_of_students, number_of_grades, grades, percentages, final_grades);
	double mean = calculate_mean(number_of_students, final_grades);
	double standard_deviation = calculate_standard_deviation(number_of_students, final_grades);
	calculate_letter_grades(number_of_students, final_grades, final_alphabetical_grades);
	get_grade_counts(number_of_students, final_alphabetical_grades, grade_counts);

	/*
	 * Should add some print outs here for everything.
	 */

	print_final_grades(number_of_students, final_grades);

	// need to free memory
	for(int i=0; i<number_of_students; i++)
	{
		free(grades[i]);
	}
//////////////////////
	int grdcnt[4];
	char chartest[4];
	int tester1d[] = { 90, 91, 95 ,86};
	calculate_letter_grades(4,tester1d, chartest);
	char gradelist[] = {'A','A','B','N'};
	get_grade_counts(4,gradelist,grdcnt);
	//printf("tester 1d %c\n",chartest[2]);
	//printf("mean is %lf\n",calculate_mean(4,tester1d));
	//printf("grade counts %d\n",grdcnt[0]);
	//printf("std dev is %lf\n",calculate_standard_deviation(4,tester1d));
	return EXIT_SUCCESS;
}

