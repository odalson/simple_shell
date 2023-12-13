#include "shell.h"

/**
 * myend - exits the shell
 * @info:contains arguments used to maintain prototype
 * Return: exits with a given exit status
 */
int myend(info_t *info)
{
	int endsee;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		endsee = erraddyoi(info->argv[1]);
		if (endsee == -1)
		{
			info->status = 2;
			printerr(info, "Unusual figure: ");
			eputs(info->argv[1]);
			eputchar('\n');
			return (1);
		}
		info->err_num = erraddyoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * mycd - current directory of  thrprocess is changed
 * @info: contains argument used to maintain prototype
 * Return: 0
 */
int _currdir(info_t *info)
{
	char *a, *dit, buffer[1024];
	int chd;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure message<<\n");
	if (!info->argv[1])
	{
		dit = _getenviron(info, "HOME=");
		if (!dit)
			chd = chdir((dit = _getenviron(info, "PWD=")) ? dit : "/");
		else
			chd = chdir(dit);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenviron(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenviron(info, "OLDPWD=")), _putchar('\n');
		chd = chdir((dit = _getenviron(info, "OLDPWD=")) ? dit : "/");
	}
	else
		chd = chdir(info->argv[1]);
	if (chd == -1)
	{
		print_error(info, "cannot change directory ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenviron(info, "OLDPWD", _getenv(info, "PWD="));
		_setenviron(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); 
	return (0);
}

