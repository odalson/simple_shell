#include "shell.h"

/**
 * @interact - returns true if shell is interactive mode
 * @info: address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimeter - checks if character is a delimeter
 * @k: the char to check
 * @delimeter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimeter(char k, char *delimiter)
{
	while (*delimeter)
		if (*delimeter++ == k)
			return (1);
	return (0);
}

/**
 * alphabet - checks for alphabetic character
 * @j: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int alphabet(int j)
{
	if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * astrtoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if there is no number in the string
 */

int astrtoi(char *s)
{
	int b, num = 1, flip = 0, display;
	unsigned int out = 0;

	for (b = 0; s[b] != '\0' && flip != 2; b++)
	{
		if (s[b] == '-')
			num *= -1;

		if (s[b] >= '0' && s[b] <= '9')
		{
			flip = 1;
			out = out * 10;
			out = out + (s[b] - '0');
		}
		else if (flip == 1)
			flip = 2;
	}

	if (num == -1)
		display = -out;
	else
		display = out;

	return (display);
}

