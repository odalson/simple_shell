#include "shell.h"

/**
 *free_point - frees a pointer and nulls the address
 * @pointer: pointer address to be free
 * Return: 1 when it is free and 0 when otherwise.
 */
int free_point(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}

