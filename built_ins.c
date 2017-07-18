#include "holberton.h"

/**
**
**
**/
int built_exit(shenv_t *se)
{
	UNUSED(se);
	_puts("built_exit\n");
	return (EXIT_SUCCESS);
}

/**
**
**
**/
int built_env(shenv_t *se)
{
	UNUSED(se);
	_puts("built_env\n");
	return (EXIT_SUCCESS);
}

