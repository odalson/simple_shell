#include "shell.h"

/**
 * display_history - displays the history list one command line  by line.
 * @info: containing arguments.
 *  Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * get_alias - gets alias to string
 * @info: parameter struct
 * @string: for the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int get_alias(info_t *info, char *string)
{
	char *k, h;
	int kepi;

	k = _strchr(str, '=');
	if (!p)
		return (1);
	h = *k;
	*k = 0;
	kepi = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias,string, -1)));
	*p = h;
	return (kepi);
}

/**
 * unget_alias - gets alias to string
 * @info: parameter struct
 * @string: for the string alias
 *
 * Return: 0 on success and otherwisw 1
 */
int unget_alias(info_t *info, char *string)
{
	char *k;

	k = _strchr(string, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unget_alias(info, string));

	unget_alias(info, string);
	return (add_node_end(&(info->alias), string, 0) == NULL);
}

/**
 * output_earliest - prints the earliast string
 * @position: the earliast position
 *
 * Return: 0 on success and otherwise 1
 */
int output_earliest(list *position)
{
	char *k = NULL, *a = NULL;

	if (position)
	{
		k = _strchr(position->string, '=');
		for (a = position->string; a <= k; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * @mimics: mimics the alias builtin (man alias)
 * @info: containing arguments
 *  Return: Always 0
 */
int mimics(info_t *info)
{
	int n = 0;
	char *k = NULL;
	list *position = NULL;

	if (info->argc == 1)
	{
		position = info->alias;
		while (position)
		{
			print_alias(position);
			position = position->next;
		}
		return (0);
	}
	for (n = 1; info->argv[n]; n++)
	{
		k = _strchr(info->argv[n], '=');
		if (k)
			unget_alias(info, info->argv[i]);
		else
			output_earliest(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

