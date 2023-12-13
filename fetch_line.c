#include "shell.h"

/**
 * put_buff – the chained commands of t he buffer
 * @info: parameter struct
 * @buffer: address of buffer
 * @length: address of length var
 *
 * Return: the read bytes
 */
ssize_t put_buff(info_t *info, char **buffer, size_t *length)
{
	ssize_t r = 0;
	size_t length_p = 0;

	if (!*length) 
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, signed_integer_hnd);
#if USEget_line
		r = getline(buffer, &length_p, stdin);
#else
		r = get_line(info, buffer, &length_p);
#endif
		if (r > 0)
		{
			if ((*buffer)[r - 1] == '\n')
			{
				(*buffer)[r - 1] = '\0'; 
				r--;
			}
			info->line_count_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			/* if (_strchr(*buffer, ';')) is this a command chain? */
			{
				*length = r;
				info->cmd_buffer = buffer;
			}
		}
	}
	return (r);
}

/**
 * get_line – retrieves a line apart from the new line
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_line(info_t *info)
{
	static char *buffer; /* the ';' command chain buffer */
	static size_t i, j, length;
	ssize_t r = 0;
	char **buffer_p = &(info->arg), *p;

	_putchar(BUFFER_FLUSH);
	r = put_buff(info, &buffer, &length);
	if (r == -1) 
		return (-1);
	if (length) 
	{
		j = i; 
		p = buffer + i; 

		check_chain(info, buffer, &j, i, length);
		while (j < length) 
		{
			if (is_chain(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1; 
		if (i >= length) 
		{
			i = length = 0; 
			info->cmd_buffer_type = CMD_NORM;
		}

		*buffer_p = p; 
		return (str_length(p)); 
	}

	*buffer_p = buffer; 
	return (r); 
}

/**
 * read_buffer – gets a buffer
 * @info: structure of parameter
 * @buffer: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buffer, READ_BUFFER_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * get_line - gets the next line of input from standard input
 * @info: parameter struct
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated pointer buffer if not NULL
 *
 * Return: s
 */
int get_line(info_t *info, char **pointer, size_t *length)
{
	static char buffer [READ_BUFFER_SIZE];
	static size_t i, length;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pointer;
	if (p && length)
		s = *length;
	if (i == length)
		i = length = 0;

	r = read_buffer(info, buffer, &length);
	if (r == -1 || (r == 0 && length == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int) (c - buffer) : length;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		string_conc(new_p, buffer + i, k - i);
	else
		string_copy(new_p, buffer + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*pointer = p;
	return (s);
}

/**
 * signed_integer_hnd – disallows ctrl c
 * signed_num: allows signed number
 * Return: 0
 */
void signed_integer_hnd(__attribute__((unused))int signed_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}

