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

int get_rank(int card_number)
{
	return card_number % NUMBER_OF_RANKS;
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
	//printf("\n card suites= %d %d %d %d %d \n",sorta[0],sorta[1],sorta[2],sorta[3],sorta[4]);
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
	//printf("\n sorted array %d %d %d %d %d \n",sorta[0],sorta[1],sorta[2],sorta[3],sorta[4]);
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
	// return value, to be set correctly in the function and then returned at the end
	bool n_of_kind = false;

	// Declare an array to hold counts of how many cards of each rank there are in the cards[] array
	// For example if cards = {1, 1, 2, 2, 2}
	//	 number_counts[1] = 2 and number_counts[2] = 3, all other indices are zero
	int number_counts[NUMBER_OF_RANKS];

	//  loop through all number_counts and initialize all counts to zero
	for(int i=0; i < NUMBER_OF_RANKS; i++)
	{
		number_counts[i] = 0 ;
	}

	// loop through all cards and increment the corresponding index in number_counts
	// no bugs are in this loop
	for(int i=0; i<array_size; i++)
	{
		number_counts[get_rank(cards[i])]++;
	}

	// loop through the array of counts for each rank
	for(int i=0; i<NUMBER_OF_RANKS;i++)
	{
		// if the count for a specific rank is equal to 2, increment pair_counts
		if(number_counts[i] >= number_of_a_kind)
		{
			n_of_kind= true;
		}
	}

	return n_of_kind;

}


/**
 * Returns if the card array has two (unique) pairs
 * @param cards The array of cards
 * @param array_size The size of the array
 * @return True/False if the card array is two pair
 */
bool is_two_pair(int cards[], int array_size)
{
	// return value, to be set correctly in the function and then returned at the end
	bool two_pair = false;

	// Declare an array to hold counts of how many cards of each rank there are in the cards[] array
	// For example if cards = {1, 1, 2, 2, 2}
	//	 number_counts[1] = 2 and number_counts[2] = 3, all other indices are zero
	int number_counts[NUMBER_OF_RANKS];

	//  loop through all number_counts and initialize all counts to zero
	for(int i=0; i < NUMBER_OF_RANKS; i++)
	{
		number_counts[i] = 0 ;
	}

	// loop through all cards and increment the corresponding index in number_counts
	// no bugs are in this loop
	for(int i=0; i<array_size; i++)
	{
		number_counts[get_rank(cards[i])]++;
	}

	// pair_counts is a counter for the number of unique pairs
	int pair_counts = 0;
	// loop through the array of counts for each rank
	for(int i=0; i<NUMBER_OF_RANKS;i++)
	{
		// if the count for a specific rank is equal to 2, increment pair_counts
		if(number_counts[i] >= 2)
		{
			pair_counts= pair_counts + 1;
		}
	}

	// if pair_counts is equal to 2
	if(pair_counts == 2)
	{
		// the hand does have two pair
		two_pair = true;
	}
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
	// return value, to be set correctly in the function and then returned at the end
	bool full_house = false;

	int number_counts[NUMBER_OF_RANKS];

	//  loop through all number_counts and initialize all counts to zero
	for(int i=0; i < NUMBER_OF_RANKS; i++)
	{
		number_counts[i] = 0 ;
	}

	// loop through all cards and increment the corresponding index in number_counts
	// no bugs are in this loop
	for(int i=0; i<array_size; i++)
	{
		number_counts[get_rank(cards[i])]++;
	}

	// pair_counts is a counter for the number of unique pairs
	int pair_counts = 0;
	int triple_counts = 0;
	// loop through the array of counts for each rank
	for(int i=0; i<NUMBER_OF_RANKS;i++)
	{
		// if the count for a specific rank is equal to 2, increment pair_counts
		if(number_counts[i] == 2)
		{
			pair_counts= pair_counts + 1;
		}
		if(number_counts[i] >= 3)
		{
			triple_counts= triple_counts + 1;
		}
	}

	// if pair_counts is equal to 2
	if((pair_counts >= 1)&&(triple_counts >= 1))
	{
		// the hand does have two pair
		full_house = true;
	}
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
	if(is_straight_flush (cards, array_size)== 1)
	{
		strength = 8;
	}
	else if(is_n_of_a_kind(cards,array_size,4) == 1)
	{
		strength = 7;
	}
	else if(is_full_house(cards,array_size) == 1)
	{
		strength = 6;
	}
	else if(is_flush(cards,array_size) == 1)
	{
		strength = 5;
	}
	else if(is_straight(cards,array_size) == 1)
	{
		strength = 4;
	}
	else if(is_n_of_a_kind(cards,array_size,3) == 1)
	{
		strength = 3;
	}
	else if(is_two_pair(cards,array_size) == 1)
	{
		strength = 2;
	}
	else if(is_n_of_a_kind(cards,array_size,2) == 1)
	{
		strength = 1;
	}
	else
	{
		strength = 0;
	}
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

	for(int i=0; i<number_of_players; i++)
	{
		int arraymake[CARDS_IN_HAND];
		for(int j=0; j < CARDS_IN_HAND ; j++)
		{
			arraymake[j]= players[i][j];
		}
		//printf("\n am array %d %d %d %d %d \n",arraymake[0],arraymake[1],arraymake[2],arraymake[3],arraymake[4]);
		printf("Player %d's card strength is %d\n",i + 1,get_hand_strength(arraymake,CARDS_IN_HAND));
	}


	int test_hand[] = {12, 16, 15, 5, 10};
	qsort(&test_hand, CARDS_IN_HAND, sizeof(int), compare);
	if(is_n_of_a_kind (test_hand, 5,2))
	{
	printf("True");
	}
	else
	{
	printf("False");
	}
	//END OF TEST CODE


	//printf("strength tester is %d\n" , get_hand_strength (tester, 5));
	return EXIT_SUCCESS;
}

