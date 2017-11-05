/*
 ============================================================================
 Name        : poker.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


//to do

//is_straight // test
//is_straight flush //test

//is n_of_akind (hint lab 3)
//is_two_pair (given lab 3)
//is_full house -iff 2 pair then shouldnt be difficult
//get had strength, not too bad, if statement and for loop

/*
 ============================================================================
 Name        : assignment2.c
 Author      : Doug
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_CARDS 52
#define CARDS_IN_HAND 5
#define NUMBER_OF_SUITES 4
#define NUMBER_OF_RANKS 13

int compare(const void* first, const void* second)
{
	int compare_value = 0;
	const int *int_one = first;
	const int *int_two = second;

	if(*int_one < *int_two)
	{
		compare_value = -1;
	}
	else if(*int_one > *int_two)
	{
		compare_value = 1;
	}

	return compare_value;
}
/*
 * Prints the array of cards (can be the deck or a hand)
 * @param cards The array of cards
 * @param array_size The size of the array
 */
void print_cards(int cards[], int array_size)
{
	for(int i=0; i<array_size; i++)
	{
		printf("%d, ", cards[i]);
	}
}

/**
 * Returns the suite of the card
 * A suite is represented as an integer 0-3
 * @param card_number The number of the card
 * @return The suite number of the card
 */
int get_suite(int card_number)
{
	return card_number / NUMBER_OF_RANKS;//was suits
}

/**
 * Returns if the card array is a flush
 * @param cards  The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is a flush
 */
bool is_flush(int cards[], int array_size)
{
	bool is_flush = true;
	for(int i = 0; i <  (array_size - 1) ;i++)
	{
		if (get_suite(cards[i]) != get_suite(cards[i+1]))
		{
			is_flush = false;
		}
	}
	return is_flush;
}

/**
 * Returns if the card array is a straight
 * Aces can be either high or low, but not both high and low
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is a straight
 */
//bool is_straight(int cards[], int array_size)
int is_straight(int cards[], int array_size)
{
	bool is_straight = true;
	int sorta[array_size];
	//make new copy array
	for(int i = 0; i < array_size ; i++)
	{
		sorta[i] = cards[i];
	}
	//make card number represent non suited card
	for(int i = 0; i < array_size ; i++)
	{
		sorta[i] = sorta[i] % 13;
	}
	printf("\n card suites= %d %d %d %d %d \n",sorta[0],sorta[1],sorta[2],sorta[3],sorta[4]);
	//sorter
	int w = 0;
	while(w == 0)
	{
		//check if sorted
		int for_int = 0;
		for(int i = 0; i <  (array_size - 1) ;i++)
				{
					if( sorta[i] > sorta[ i + 1 ])
					{
						for_int = 1;
					}
				}
		if (for_int == 0)
		{
			w = 1;
		}
		for(int i = 0; i <  (array_size - 1) ;i++)
		{
			if( sorta[i] > sorta[ i + 1 ])
			{
				int num1 = sorta[i];
				int num2 = sorta[i+1];
				sorta[i] = num2;
				sorta[i + 1] = num1;
			}
		}
	}
	printf("\n sorted array %d %d %d %d %d \n",sorta[0],sorta[1],sorta[2],sorta[3],sorta[4]);
	//check for basic non high ace flush
	for(int i = 0; i <  (array_size - 1) ;i++)
	{
		if (((sorta[i]) + 1) != (sorta[i+1]))
		{
			is_straight = false;
		}
	}
	//making sure 01234 doesnt give false in next part,works wo
	if(is_straight == true)
	{
		sorta[0]= 1;
	}
	//check for high ace flush
	int high_ace = 1;
	if(sorta[0] != 0)
	{
		high_ace = 0;
	}
	for(int i = 0; i <  (array_size - 1) ; i++)
	{
		if (sorta[array_size - 1 - i] != 12 - i)
		{
			high_ace = 0;
		}
	}

	if(high_ace == 1)
	{
		is_straight = true;
	}
	return is_straight;
}

/**
 * Returns if the card array is a straight-flush
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is a straight-flush
 */
bool is_straight_flush(int cards[], int array_size)
{
	bool straight_flush = false;

	if( (is_straight (cards,array_size)) &&  (is_flush (cards,array_size)) )
	{
		straight_flush = true;
	}
	return straight_flush;
}

/**
 * Returns if the card array is n of a kind
 * @param cards The array of cards
 * @param array_size The size of the array
 * @param number_of_a_kind How many of the same rank there needs to be (2, 3, or 4)
 * @return True/False if the card array is 'n' of a kind
 */
bool is_n_of_a_kind(int cards[], int array_size, int number_of_a_kind)
{
	printf("number of a kind is %d\n", number_of_a_kind);
	bool n_of_a_kind = false;
	int sorta[array_size];
	for(int i = 0; i < array_size ; i++)
	{
		sorta[i] = cards[i];
	}
	for(int i = 0; i < array_size ; i++)
	{
		sorta[i] = sorta[i] % 13;
	}
	int w = 0;
	while(w == 0)
	{
		int for_int = 0;
		for(int i = 0; i <  (array_size - 1) ;i++)
		{
			if( sorta[i] > sorta[ i + 1 ])
			{
				for_int = 1;
			}
		}
		if (for_int == 0)
		{
			w = 1;
		}
		for(int i = 0; i <  (array_size - 1) ;i++)
		{
			if( sorta[i] > sorta[ i + 1 ])
			{
				int num1 = sorta[i];
				int num2 = sorta[i+1];
				sorta[i] = num2;
				sorta[i + 1] = num1;
			}
		}
	}
	//printf("\n sorted array  n of a kind ,%d %d %d %d %d \n",sorta[0],sorta[1],sorta[2],sorta[3],sorta[4]);
	//now actual n of a kind
	int kind[array_size + 1 - number_of_a_kind];
	for(int i = 0; i <=  (array_size - number_of_a_kind) ;i++)
	{
		int kind2[number_of_a_kind - 1];
		for(int w = 0; w < (number_of_a_kind - 1); w++)
		{
			kind2[w] = 1;
		}
		for(int b = 0 ; b < (number_of_a_kind - 1 ) ; b++)
		{
			if(sorta[b+i] != sorta[b+i+1])  //not working
			{
				kind2[b]=0;
			}
		}

		//printf("kind2 is after checking if the same %d %d\n", kind2[0],kind2[1]); // change to fit kind2specs
		kind[i]= 1;
		for(int e = 0 ; e < number_of_a_kind - 1 ;e++)
		{
			if(kind2[e] != 1 )
			{
				kind[i] = 0;
			}
		}
	}
	for(int q = 0 ; q < (array_size  - number_of_a_kind) ; q++)
	{
		if( kind[q] == 1)
		{
			n_of_a_kind = true;
		}
	}
	return n_of_a_kind;
}

/**
 * Returns if the card array has two (unique) pairs
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is two pair
 */
bool is_two_pair(int cards[], int array_size)
{
	bool two_pair = false;

	// leave untouched until the lab

	return two_pair;
}

/**
 * Returns if the card array is a full house
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is a full house
 */
bool is_full_house(int cards[], int array_size)
{
	bool full_house = false;

	// similar to is_two_pair

	return full_house;
}

/**
 * Returns the strength of the hand
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return An integer representing thee strength of the hand
 */
int get_hand_strength(int cards[], int array_size)
{
	int strength = 0;

	// leverage all the other functions
	// if...else if...else if...

	return strength;
}

int main(int argc, const char* argv[])
{

	int number_of_players;

	/*
	 * read from user input if no runtime arguments were specified
	 */
	if (argc < 2)
	{
	    // assume integer input
		// note scanf is discouraged, but is simplest for now
		printf("Enter a number of players\n");
		scanf("%d", &number_of_players);
		printf("\n");
	}
	else
	{
		number_of_players = atoi(argv[1]);
	}

	if(number_of_players < 0 || number_of_players*CARDS_IN_HAND > NUMBER_OF_CARDS)
	{
		int max_players = NUMBER_OF_CARDS / CARDS_IN_HAND;
		printf("Number of players must be > 0 and < %d", max_players);
		exit(-1);
	}

	//

	int random_seed = 7;
	srand(random_seed);

	//

	int deck[NUMBER_OF_CARDS];

	// create deck
	for(int i=0; i<NUMBER_OF_CARDS; i++)
	{
		deck[i] = i;
	}

	print_cards(deck, NUMBER_OF_CARDS);
	printf("\n");

	// shuffle deck
	for(int i=0; i<NUMBER_OF_CARDS; i++)
	{
		int random_index = rand();
		random_index = random_index % NUMBER_OF_CARDS;

		// swap
		int temp = deck[i];
		deck[i] = deck[random_index];
		deck[random_index] = temp;
	}

	print_cards(deck, NUMBER_OF_CARDS);
	printf("\n");


	///////////////////////////////////////////////////////////////////

	printf("\n");

	// deal cards to some number of players
	int players[number_of_players][CARDS_IN_HAND];

	for(int i=0; i<number_of_players*CARDS_IN_HAND; i++)
	{
		players[i%number_of_players][i/number_of_players] = deck[i];
	}

	for(int i=0; i<number_of_players; i++)
	{
		qsort(&players[i], CARDS_IN_HAND, sizeof(int), compare);
		print_cards(players[i], CARDS_IN_HAND);
		printf("\n");
	}


	/*
	 * print out each players hand strength here
	 */

	int tester[5];
	tester[0]= 4;
	tester[1]= 0;
	tester[2]= 0;
	tester[3]= 0;
	tester[4]= 0;
	printf("\n tester array %d %d %d %d %d \n",tester[0],tester[1],tester[2],tester[3],tester[4]);
	//printf("suite not same? %d\n",get_suite (tester[0])!=get_suite(tester[1])  );
	//printf("tester is_flush %d\n",is_flush(tester, 5) );
	//printf("tester straight %d\n", is_straight(tester,5 ) );
	//printf("tester straight_flush %d\n", is_straight_flush (tester,5 ) );
	printf("is 4 of a kind %d\n", is_n_of_a_kind (tester,5,4 ) );


	return EXIT_SUCCESS;
}

