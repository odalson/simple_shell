#include "shell.h"

/**
 * conv_str – changes a string to integer
 * @string: the converted string
 * Return: 0 if there is no numberber in the string and -1 on error otherwise
 */
int conv_str (char *string)
{
	int i = 0;
	unsigned long int output = 0;

	if (*string == '+')
		string++; 
	for (i = 0;  string[i] != '\0'; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			output = output * 10;
			output = output + (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}

/**
 * prnt_err – outputs the error message
 * @info: returns the parameter and the information structure
 * @error_str: the string containing a specified error
 * Return: 0 if there is no numberber in the string and -1 on error otherwise
 */
void prnt_err(info_t *info, char *error_str)
{
	_eputs(info->fname);
	_eputs(": ");
	prnt_decimal(info->line_c, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(error_str);
}

/**
 * prnt_decimal - function prints a decimal (integer) numberber (b 10)
 * @put_in: the entry data
 * @file_des: the file descriptor to be written to
 * Return: the numberber of characters to be printed
 */
int prnt_decimal(int put_in, int file_des)
{
	int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int ab_s, curnt;

	if (file_des == STDERR_FILENO)
		__putchar = _eputchar;
	if (put_in < 0)
	{
		ab_s = ab_s – put_in;
		__putchar('-');
		c++;
	}
	else
		ab_s = put_in;
	curnt = ab_s;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (ab_s / i)
		{
			__putchar('0' + curnt / i);
			c++;
		}
		curnt %= i;
	}
	__putchar('0' + curnt);
	c++;

	return (c);
}

/**
 * _con_number – function for converting 
 * @numberber: represents numberber
 * @b: represents b
 * @flags: represents argument flags
 *
 * Return: a string
 */
char *_con_number(long int number, int b, int flags)
{
	static char *array;
	static char bufferfer[50];
	char sign = 0;
	char *ptrs;
	unsigned long n = number;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptrs = &bufferfer[49];
	*ptrs = '\0';

	do	{
		*--ptrs = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptrs = sign;
	return (ptrs);
}

/**
 * rem_com - function replaces first instance of '#' with '\0'
 * @bufferfer: address of the string to modify
 *
 * Return: 0;
 */
void rem_com(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}

