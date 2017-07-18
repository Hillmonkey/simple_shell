#include "holberton.h"

/**
**execute_builtin - 
**@args:
**Return: int
**/


int execute_builtin(shenv_t *se)
{

	
	built_t built_in[] = {
	{"exit", built_exit},
	{"env", built_env},
	{NULL, NULL},
	};



	int status;
	int i;

	if (se->cmd_tokens == NULL || se->cmd_tokens[0] == NULL)
		return (1);

	for (i = 0; i < number_builtins(built_in); i++)
	{
		if(_strcmp(se->cmd_tokens[0], built_in[i].name) == 0)
		{
			status = built_in[i].p(se);
			return (status);
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

	int i = 0; 
	
	while (built_in[i].name != NULL)
		i++;
	return (i);
}
