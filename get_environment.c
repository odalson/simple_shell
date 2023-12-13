#include "shell.h"

/**
 * get_env – gets the copy of array of string of our environment
 * @info: containing arguments
 * Return: Always 0
 */
char **get_env(info_t  *info)
{
	if (!info->env || info->env_changed)
	{
		info->env = ist_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->env);
}

/**
 * rmv_env_variable – remove an environment variableiable
 * @info: containing argument
 *  Return: I on success and 0 otherwise
 * @variable: the property of variableiable in an environment string
 */
int rmv_env_variable(info_t *info, char *variable)
{
	list_t *position = info->env;
	size_t i = 0;
	char *p;

	if (!position || !variable)
		return (0);

	while (position)
	{
		p = starts_with(position->str, variable);
		if (p && *p == '=')
		{
			info->env_changed = delete_position_at_index(&(info->env), i);
			i = 0;
			position = info->env;
			continue;
		}
		position = position->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * set_environment – start a new environment and edit an existing environment
 * @info: containing arguement
 * @variable: the string environment variable property
 * @value: the string env variable value
 *  Return: Always 0
 */
int set_environment (info_t *info, char *variable, char *value)
{
	char *buffer = NULL;
	list_t *position;
	char *p;

	if (!variable || !value)
		return (0);

	buffer = malloc(_strlen(variable) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, variable);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	position = info->env;
	while (position)
	{
		p = starts_with(position->str, variable);
		if (p && *p == '=')
		{
			free(position->str);
			position->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		position = position->next;
	}
	add_position_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}

