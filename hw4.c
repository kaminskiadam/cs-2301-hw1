/*
 ============================================================================
 Name        : assignment4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment_4.h"
#include "vigenere.h"

// The maximum number of characters to expect for strings in the program including '\0'
#define MAX_CHARACTERS 1000

// The size of the alphabet being used
const int ALPHABET_SIZE = 28;

// The alphabet
const char ALPHABET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
							  'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
							  'W', 'X', 'Y', 'Z', ' ', '.', '\0'};

/**
 * Reads input from the program arguments if the correct number of arguments are supplied.
 * If there are two program arguments, the first argument is the plain text and the
 * second argument is the encryption key.  If there are not enough arguments, the
 * plain text and encryption key will be read in from the user using fgets.
 *
 * @param plain_text_length
 * 			An integer passed in by the value of its address from the main program.
 *			This variable will hold the length of the plain text. Length does not include the '\0' character.
 *			The pointer will not change (hence the const keyword), however the dereferences value will.
 *
 * @param encryption_key_length
 * 			An integer passed in by the value of its address from the main program.
 *			This variable will hold the length of the encryption key. Length does not include the '\0' character.
 *			The pointer will not change (hence the const keyword), however the dereferences value will.
 *
 * @param plain_text
 * 			A character array to store the plain text either from program arguments or from user input
 * 			Do not forget to add '\0' to the end of the string.
 *
 * @param encryption_key
 * 			A character array to store the encryption key either from program arguments or from user input
 * 			Do not forget to add '\0' to the end of the string.
 *
 * @param argc
 * 			argc from the main program.  Needed to get information from argv.
 *
 * @param argv
 * 			argv from the main program.  Use this to read values from argv just like we have previously done.
 */
void read_input(int *const plain_text_length, int *const encryption_key_length, char plain_text[], char encryption_key[], const int argc, const char *const argv[])
{
	// read input
	// check if argc is the correct size
	if(argc == 3)
	{
		strcpy(plain_text,argv[1]);
		strcpy(encryption_key,argv[2]);
	}
		// if there are program arguments
			// read from the program arguments
			// argv[1] has the plain text
			// argv[2] has the encryption_key
	else
	{
		printf("enter the plain text\n");
		if(fgets (plain_text,MAX_CHARACTERS,stdin) == NULL)
		{
			printf("fgets failed\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			plain_text[strcspn(plain_text, "\n")] = '\0';
		}
		printf("enter the key\n");
		if(fgets (encryption_key,MAX_CHARACTERS,stdin) == NULL)
		{
			printf("fgets failed\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			encryption_key[strcspn(encryption_key, "\n")] = '\0';
		}

	}
	*plain_text_length = strlen(plain_text);
	*encryption_key_length = strlen(encryption_key);
			// read from user input
			// prompt user for input and use fgets for each string
			// make sure to check that fgets is successful
				// if not successful execute the following two lines
					//printf("fgets failed\n");
					//exit(EXIT_FAILURE);
			// note that fgets will also store the newline character that the user enters
			// this character should be replaced with '\0'. It will be the last character in the string
			// store the lengths of the plain text and encryption key into the respected lengths (see parameters)


}

int main(int argc, const char *argv[])
{

	// Integer variable to store the length of the plain text
	int plain_text_length;

	// Integer variable to store the length of the encryption key
	int encryption_key_length;

	// Character array to hold the plain text
	char plain_text[MAX_CHARACTERS];

	// Character array to hold the encryption key
	char encryption_key[MAX_CHARACTERS];

	// Read input
	// Call read_input with the correct arguments (and the correct form)
	read_input(&plain_text_length,&encryption_key_length,plain_text,encryption_key, argc, argv);


	// Convert plain_text and encryption_key to lower case
	// Call the to_lower in vigenere.c
	// Modification are made to the current strings, nothing is returned by the function
	to_lower(plain_text);
	to_lower(encryption_key);


	// Create a variable called same_length_encryption_key
	// This variable is used to store the encryption key modified to be the same length as the plain text
	// Call the function generate_same_length_key in vigenere.c with appropriate parameters

	char same_length_encryption_key [plain_text_length + 1];
	generate_same_length_key(plain_text_length , encryption_key ,same_length_encryption_key);



	// Create a variable called vigenere_table
	// This is an array of character pointers to hold store the vigenere table
	char *vigenere_table[ALPHABET_SIZE];

	// Need to allocate memory
	for(int i=0; i<ALPHABET_SIZE; i++)
	{
		vigenere_table[i] = malloc(sizeof(char) * ALPHABET_SIZE);
	}

	// Call generate_vigenere_table in vigenere.c with the appropriate parameters
	generate_vigenere_table(ALPHABET_SIZE,ALPHABET,vigenere_table);
	/*
	for(int a = 0 ; a < ALPHABET_SIZE ; a++)
	{
		printf("\n");
		for(int b = 0 ; b < ALPHABET_SIZE ; b++)
		{
			printf("%c",vigenere_table [a][b]);
		}
	}
	*/

	// Create a variable called encrypted_text to store the encrypted text
	// This variable is an array of characters with the same length as the plain text (+1 for '\0')
	char encrypted_text [plain_text_length +1];


	// Encrypt the plain text
	// Call the encrypt function in vigenere.c with the appropriate variables
	encrypt(plain_text,same_length_encryption_key, encrypted_text, ALPHABET ,vigenere_table);




	// Create a variable called decrypted_text to store the decrypted text
	// This variable is an array of characters with the same length as the plain text (+1 for '\0')
	char decrypted_text [plain_text_length +1];

	// Decrypt the plain text
	// Call the decrypt function in vigenere.c with the appropriate variables

	decrypt(encrypted_text,same_length_encryption_key, decrypted_text, ALPHABET ,vigenere_table);


	// Print statements for your convenience
	// You do not need to modify any lines below this point (unless you want to)

	///*
	printf("Plain text length = %d\n", plain_text_length);
	printf("Encryption key length = %d\n", encryption_key_length);

	printf("Plain text = \"%s\"\n", plain_text);
	printf("Encryption key = \"%s\"\n", encryption_key);

	printf("Same length encryption key = \"%s\"\n", same_length_encryption_key);

	printf("Alphabet:\n");

	for(int i=0; i<ALPHABET_SIZE; i++)
	{
		printf("%c", ALPHABET[i]);

		if(i < ALPHABET_SIZE-1)
		{
			printf(", ");
		}
	}
	printf("\n");
///*
	printf("Vigenere Table:\n");

	for(int i=0; i<ALPHABET_SIZE; i++)
	{
		for(int j=0; j<ALPHABET_SIZE; j++)
		{
			printf("%c", vigenere_table[i][j]);

			if(j < ALPHABET_SIZE-1)
			{
				printf(", ");
			}
		}

		printf("\n");
	}
//*/
	printf("Encrypted text = %s\n", encrypted_text);
	printf("Decrypted text = %s\n", decrypted_text);
	//*/

	// Need to free memory
	for(int i=0; i<ALPHABET_SIZE; i++)
	{
		free(vigenere_table[i]);
	}

	return 0;

}

