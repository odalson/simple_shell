#include "shell.h"

/**
 * in_put: inputs a string
 * @string: prints string
 *
 * Return: 0
 */
void in_put(char *string)
{
	int n = 0;

	if (!string)
		return;
	while (string[n] != '\0')
	{
		in_putchar(string[n]);
		n++;
	}
}

/**
 * in_putchar - writes the character 
 * @m: The character to print
 *
 * Return: prints 1 on success
 * Returns -1 when is error and error number set appropriately
 */
int in_putchar(char m)
{
	static int n;
	static char buffer[BUFF_SIZE];

	if (m == BUFFER_FLUSH || n >= BUFF_SIZE)
	{
		write(2, buffer, n);
		n = 0;
	}
	if (m != BUFFER_FLUSH)
		buf[n++] = m;
	return (1);
}

/**
 * wri_filedes - writes the character n to a file descriptor
 * @m: The character to print
 * @filedes: File descriptor to be written to
 *
 * Return: prints 1 on success
 * Returns -1 when is error and error number set appropriately
*/
int wri_filedes(char m, int filedes)
{
	static int n;
	static char buffer[BUFF_SIZE];

	if (m == BUFFER_FLUSH || n >= BUFF_SIZE)
{
		write(filedes, buffer, n);
		n = 0;
	}
	if (m != BUFFER_FLUSH)
		buffer[n++] = m;
	return (1);
}

/**
 * print_str - prints an input string
 * @string: the string to be printed
 * @filedes: the filedescriptor to be written to
 *
 * Return: the number of chars put
 */
int print_str(char *string, int filedes)
{
	int n = 0;

	if (!string)
		return (0);
	while (*string)
	{
		n = n + print_str(*string++, filedes);
	}
	return (n);

