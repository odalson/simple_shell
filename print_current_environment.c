#include "shell.h"

/**
 * my_environment - print current environment
 * @info: containing arguments
 * Return: Always 0
 */
int my_environment(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_environment - gets the value of the environment
 * @info: contains argument
 * @name: variable name for environment
 *
 * Return: value of the environment
 */
char *get_environment(info_t *info, const char *name)
{
	list_t *position = info->environment;
	char *k;

	while (position)
	{
		k = starts_with(position->str, name);
		if (k && *k)
			return (k);
		position = position->next;
	}
	return (NULL);
}

/**
 * set_environment - sets a new environment
 * info: containing argument
 * Return: Always 0
 */
int set_environment(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("argument number is not correct\n");
		return (1);
	}
	if (set_environment(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * rmv_environment - Remove the variable of an environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int rmv_environment(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Parameter or Argument is too small.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		rmv_environment(info, info->argv[j]);

	return (0);
}

/**
 * fill_environment - fill environment with linked list
 * @info: contain arguments
 * Return: Always 0
 */
int fill_environment(info_t *info)
{
	list_t *position = NULL;
	size_t j;

	for (j = 0; env[j]; j++)
		add_node_end(&position, env[j],0);
	info->environment = position;
	return (0);
}

