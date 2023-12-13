#include "shell.h"

/**
 *string_copy- string copied
 *@destination: the destination string to be copied to
 *@source_string: the source string
 *@n: the amount of characters to be copped
 *Return: the concatenated string
 */
char *string_copy(char *destination, char *source_string, int n)
{
	int p, j;
	char *s = destination;

	p = 0;
	while(source_string[p] != '\0' && p < n - 1)
	{
		destination[p] = source_string[p];
		p++;
	}
	if (p < n)
	{
		j = p;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **string_conc - joins two or more strings
 *@destination: the first joined string
 *@source_string: the second string
 *@n: amount of bytes to be used
 *Return: the concatenated string
 */
char *string_conc(char *destination, char *source_string, int n)
{
	int p, j;
	char *s = destination;

	p = 0;
	j = 0;
	while (destination[p] != '\0')
		p++;
	while (source_string[j] != '\0' && j < n)
	{
		destination[p] = source_string[j];
		p++;
		j++;
	}
	if (j < n)
		destination[p] = '\0';
	return (s);
}

/**
 **string_char - locates a character pin a string
 *@str: the string to be parsed
 *@c_a: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *string_char(char *str, char c_a)
{
	do {
		if (*str== c_a)
			return (s);
	} while (*str++ != '\0');

	return (NULL);
}

