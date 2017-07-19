#include "holberton.h"

/**
 * init_env - Initialize environment struct
 * @se: pointer to struct that holds vars for passing to functions
 **/

void init_env(shenv_t *se)
{
	/* se->pid = DUD */
	se->status = 0;
	se->linebuf = NULL;
	se->linelen = 0;
	se->linesize = 0;
	se->counter = 0;
	/* get rid of se->my_argv[] later */
}


/**
 * init_cmd_tokens - wipe all contents of buffer to default value
 * @se: Shell Environment struct
 * Return: EXIT_SUCCESS
 **/
int init_cmd_tokens(shenv_t *se)
{
	int i;
	char *default_value = NULL;

	for (i = 0; i < BUFSIZE; i++)
	{
		/* printf("cmd_token[%d] = %p\n", i, se->cmd_tokens[i]); */
		se->cmd_tokens[i] = default_value;
	}
	return (EXIT_SUCCESS);
}

/**
 * init_path_tokens - wipe all contents of buffer to default value
 * @se: Shell Environment struct
 * Return: EXIT_SUCCESS
 **/
int init_path_tokens(shenv_t *se)
{
	int i;
	char *default_value = NULL;

	for (i = 0; i < BUFSIZE; i++)
	{
		/* printf("path_token[%d] = %p\n", i, se->path_tokens[i]); */
		se->path_tokens[i] = default_value;
		/* buffer[i] = NULL; */
	}
	return (EXIT_SUCCESS);
}

