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
	
	_puts("built_p_env\n");

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

