/*
 * vigenere.c
 *
 *  Created on: Nov 18, 2017
 *      Author: student
 */

#include <ctype.h>
#include <string.h>
#include "vigenere.h"

/**
 * Converts the array of characters to lower case
 * Use the tolower function in <ctype.h>
 *
 * @param character_array
 * 				The array of characters
 */
void to_lower(char character_array[])
{
	int b = 0;
	while(character_array[b] != '\0')
	{
		character_array[b]= tolower(character_array[b]);
		b++;
	}
}

/**
 * Takes the encryption_key and the length of the plain text as parameters.
 * Will generate a new encryption key, which is the same length as the plain text
 * by repeating the characters in the original encryption key as many times as necessary.
 *
 * @param plain_text_length
 * 				The length of the plain text
 *
 * @param encryption_key
 * 				The encryption key
 *
 * @param same_length_key
 * 				A characters array to store the new encryption key which is the same length as the plain text
 */
void generate_same_length_key(const int plain_text_length, const char encryption_key[], char same_length_key[])
{
	int L = strlen(encryption_key);
	int b = 0;
	for(int i = 0 ;i < plain_text_length;i++)
	{
		same_length_key[i] = encryption_key[i - (b*L)];
		if((L - 1) == (i - (b * L)) )
		{
			b++;
		}
	}
	same_length_key[plain_text_length] = '\0';
}

/**
 * Generates a vigenere table based on the input parameters
 *
 * @param alhpabet_size
 * 				The size of the alphabet (number of characters)
 * @param alphabet
 * 				A character array storing the alphabet
 * 				['A', 'B', ...]
 *
 * @param vigenere_table
 * 				A two-dimensional character array storing the Vigenere table
 * 				['A', 'B', ...]
 * 				['B', 'C', ...]
 * 				...
 */
void generate_vigenere_table(const int alhpabet_size, const char alphabet[alhpabet_size], char *vigenere_table[alhpabet_size])
{
	for(int a = 0 ; a < alhpabet_size ; a++)
	{
		for(int b = 0 ; b < alhpabet_size ; b++)
		{
			vigenere_table [a][b] = alphabet[(a+b) % alhpabet_size];
		}
	}
}

/**
 * Encrypts the plain text using the encryption key.  Stores the encrypted text in the variable encrypted_text.
 * Use the Vigenere encryption algorithm to encrypt the text.
 * For learning purposes, use pointer arithmetic instead of array indexing
 *
 * @param plain_text
 * 				A character array of plain text
 *
 * @param encryption_key
 * 				A character array for the encryption key.  This is assuemd to be the same length as the plain text.
 * 				No error checking is required.
 *
 * @param encrypted_text
 * 				A character array to store the encrypted text.
 *
 * @param alphabet
 * 				A character array storing the alphabet.  This may be useful when implementing the algorithm
 *
 * @param vigenere_table
 * 				A two-dimensional character array representing the Vigenere table
 */
void encrypt(const char plain_text[], const char encryption_key[], char encrypted_text[], const char alphabet[], char *vigenere_table[])
{
	int length = strlen(plain_text);
	for(int i = 0 ; i < length; i++ )
	{
		encrypted_text[i] = vigenere_table  [get_index(plain_text[i],alphabet)]   [get_index(encryption_key [i],alphabet)];
		//*(encrypted_text + i) = * ( * (vigenere_table + (get_index(plain_text[i],alphabet))) + (get_index(encryption_key [i],alphabet)));
	}
	encrypted_text[length]= '\0';
}

/**
 * Decrypts the cipher text (encrypted text) using the encryption key.  Stores the decrypted text
 * in the variable plain_text.
 * Use the Vigenere encryption/decryption algorithm to decrypt the text.
 * For learning purposes, use pointer arithmetic instead of array indexing
 *
 * @param encrypted_text
 * 				A character array storing the encrypted text
 *
 * @param encryption_key
 * 				A character array storing the encryption key.
 *
 * @param plain_text
 * 				A character array to store the decrypted text in.
 *
 * @param alphabet
 * 				A character array storing the alphabet.  This may be useful when implementing the algorithm
 *
 * @param vigenere_table
 * 				A two-dimensional character array representing the Vigenere table
 */
void decrypt(const char encrypted_text[], const char encryption_key[], char plain_text[], const char alphabet[], char *vigenere_table[])
{
	int length = strlen(encrypted_text);
	int allength = strlen(alphabet);
	for(int i = 0 ; i < length; i++ )

	{
		//encrypted_text[i] = vigenere_table  [get_index(plain_text[i],alphabet)]   [get_index(encryption_key [i],alphabet)];
		//*(plain_text + i) = * ( * (vigenere_table + (get_index(plain_text[i],alphabet))) + (get_index(encryption_key [i],alphabet)));
		//plain_text[i] = tolower(alphabet[ abs(((get_index(encrypted_text[i],alphabet))-(get_index(encryption_key[i],alphabet) )) % allength)]);
		*(plain_text + i) = tolower(alphabet[ (allength + (get_index(*(encrypted_text + i),alphabet))-(get_index(*(encryption_key + i ),alphabet) ))% allength]);
	}
	plain_text[length]= '\0';

}

/**
 * Given a character (current_char) and an alphabet, finds the index where the character is
 * located in the alphabet.  This may be useful when encrypting/decrypting.
 * The character comparison should be case-insensitive.
 *
 * @param current_char
 * 			A character
 *
 * @param alphabet
 * 			An array of characters
 *
 * @return
 * 		Returns the index of current_char in the alphabet array
 */
int get_index(const char current_char, const char alphabet[])
{
	int row_index = -1;

	int length = strlen(alphabet);
	for(int i = 0 ; i < length ; i++ )
	{
		if(tolower(alphabet[i]) == tolower(current_char))
		{
			row_index = i ;
		}
	}
	return row_index;
}

