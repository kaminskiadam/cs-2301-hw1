/*
 ============================================================================
 Name        : assignment5.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

/**
 * Initializes an empty list with an initial size of one block.
 * 		This means memory for one block will need to be allocated
 * 		In this scenario, the memory will NOT be freed inside this function
 * Sets the current_size to 0
 * Sets the total_size to the block_size
 * Sets the block _size to block_size
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 *
 * @param block_size
 * 			The size of a block.
 * 			This is used when increasing the size of the array
 *
 * @param element_size
 * 				The size of each element stored in the list.
 * 				The list is assumed to be homogeneous (all elements are the same type)
 * @return
 * 		Returns 0 if successful, -1 if unsuccessful
 */
int initialize(array_list_t *array_list, int block_size, int element_size)
{
	/*
	*array_list = malloc(sizeof(array_list_t));
	if(array_list == NULL)
	{
		printf("malloc failed");
		exit(EXIT_FAILURE);
	}
	*/
	int *pointer_array = malloc(block_size*element_size);
	if(pointer_array == NULL)
		{
			printf("malloc failed");
			exit(EXIT_FAILURE);
		}
	array_list->current_size = 0;
	array_list->total_size = block_size;
	array_list->block_size = block_size;
	array_list->number_of_blocks = 1;
	array_list->array = pointer_array;
	return 0;
}

/**
 * Frees the memory for the dynamically allocated array in the list
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 */
void free_list(array_list_t *array_list)
{
	free(array_list->array);
	array_list->array = NULL;

}

/**
 * Adds an element to the specified index of the list
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 *
 * @param element
 * 			A pointer to the element to add to the list
 *
 * @param element_size
 * 			The size of the element (in bytes)
 *
 * @param index
 * 			The index to add the element.  The element will be placed
 * 			at this index.
 * @return
 * 		Returns 0 if successful, -1 if unsuccessful
 */
int add_element(array_list_t *array_list, int *element, int element_size, int index)
{
	// TODO IMPLEMENT

	// check for valid index
	// allocate another block of memory if needed
	if(array_list-> current_size >= array_list-> total_size )
	{
		int *new_array = malloc((array_list->total_size + array_list->block_size)* sizeof(void*));
		if(new_array == NULL)
			{
				printf("malloc failed");
				exit(EXIT_FAILURE);
			}
		memcpy(new_array,array_list->array,(array_list->total_size)*sizeof(void*));
		free_list(array_list);
		array_list->total_size = array_list->total_size + array_list->block_size;
		array_list->number_of_blocks = array_list->number_of_blocks + 1;
		array_list->array = new_array;
	}


	// shift all other elements up to make room for the new element
		// use memmove to shift
	memmove(&(array_list->array)[1+ index],&(array_list->array)[index],((array_list->current_size)*element_size)+1);
	// copy the new element into the array
		// use memcpy to copy
	memcpy(&(array_list->array)[index],element,element_size);
	// increment current_size
	array_list->current_size = array_list->current_size + 1;



	return 0;
}

/**
 * Remove an element from the list.
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 *
 * @param element_size
 * 			The size of the element (in bytes)
 *
 * @param index
 * 			The index of the element to remove
 *
 * @return
 * 		Returns the a pointer to the element that was removed, NULL if unsuccessful
 */
void *remove_element(array_list_t *array_list, int element_size, int index)
{
	// TODO IMPLEMENT

	// check for valid index


	// create an integer pointer with malloc(element_size)
	// use memcpy to copy the element to remove into the integer pointer
	// shift all other elements down
		// use memmove to shift
	// decrement current_size
	// return the integer pointer pointing to a copy of the element that was removed

	return NULL;
}

/**
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 *
 * @param element
 * 			The element to set
 *
 * @param element_size
 * 			The size of the element (in bytes)
 *
 * @param index
 * 			The index of the element to set
 * @return
 * 			Returns a pointer to the previous element, NULL if unsuccessful
 */
void *set_element(array_list_t *array_list, int *element, int element_size, int index)
{
	// TODO IMPLEMENT
	// check for valid index


	// create an integer pointer with malloc(element_size)
	// use memcpy to copy the element being replaced into the integer pointer
	// use memcpy to copy the new element into the array
	// return a pointer to previous element

	return NULL;
}

/**
 * Returns the address of the element at the specified index
 *
 * @param array_list
 * 			A pointer to the array_list_t structure
 *
 * @param element_size
 * 			The size of the element (in bytes)
 *
 * @param index
 * 			The index of the element to get
 *
 * @return
 * 			Returns a pointer to the element, NULL if unsuccessful
 */
void *get_element(array_list_t *array_list, int element_size, int index)
{
	// TODO IMPLEMENT

	// check for valid index

	// return the address if the element at the specified index

	return NULL;

}

