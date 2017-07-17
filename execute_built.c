#include "holberton.h"

/**
**execute_builtin - 
**@args:
**Return: int
**/


int execute_builtin(char **args)
{

	int built_exit(char **args)
	int built_env(char **args)
	
	built_t built_in[] = {
	{"exit", built_exit},
	{"env", built_env},
	{NULL, NULL}
	};built_t




	int i;

	if (args[0] == NULL)
		return (1);

	for (i = 0; i < number_builtins( ); i++)
	{
		if(_strdup(args[0], built_in[i]) == 0)
		{
			return (built_in[i].p)();
		}
	}
	return (1);
}
/**
**number_builtin - 
**@built_t:
**Return: int
**/
int number_builtins(built_t built_in[])
{

	int i; 
	
	while (built_in[i].name != NULL)
		i++;
	return (i);
}
