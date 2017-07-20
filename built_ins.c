#include "holberton.h"

/**
**built_exit - exit builtin
**@se: shell env
**Return: exit
**/
int built_exit(shenv_t *se)
{
	UNUSED(se);
	_puts("built_exit\n");
	return (EXIT_SUCCESS);
}

/**
**built_p_env - environment builtin
**@se: shell envi
**Return: the env
**/
int built_p_env(shenv_t *se)
{
	UNUSED(se);

	int i = 0;
	

	if (environ == NULL)
	{
		perror("hsh environment list is NULL");
		return (EXIT_FAILURE);

	}
	
	for (; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}	
	return (EXIT_SUCCESS);
}

/**
**built_help - environment builtin
**@se: shell envi
**Return: the env
**/
int built_help(shenv_t *se)
{
        UNUSED(se);

	built_t built_in[] = {
	{"exit", built_exit},
	{"env", built_p_env},
	{"help", built_help},
	{NULL, NULL},
	};
	int status;
	int i;
		
	if (se->cmd_tokens[1] == NULL)
	{
		_puts("help usage: help COMMAND\n    ");
		_puts("Prints out information on builtin commands\n");
		return (0);
	}
	else
	{
		for (i = 0; i < number_builtins(built_in); i++)
		
		if (_strcmp(se->cmd_tokens[0], built_in[i].name) == 0)
		{
			status = built_in[i].p(se);
			return (status);
		}
	}
	_puts("No help topics match\n");
	return (EXIT_FAILURE);
}
