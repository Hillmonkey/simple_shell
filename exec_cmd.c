#include "holberton.h"
/**
** exec_cmd - executes commands
** @se: arg
** Return: void
**/
void exec_cmd(shenv_t *se)
{
	char *my_argv[2];

	my_argv[0] = strtok(se->linebuf, DELIM);
	my_argv[1] = NULL;
	/* printf("linebuf = %s", linebuf); */
	if (se->linelen > 0)
	{
		switch (se->pid = fork())
		{
			case -1:
				perror("fork()");
			case 0: /* child */
				se->status = execve(my_argv[0], my_argv, NULL);
				exit(se->status);
			default: /* parent */
				if (waitpid(se->pid, &(se->status), 0) < 0)
				{
					perror("waitpid()");
					exit(EXIT_FAILURE);
				}
		}
	}
	else
		if (is_interactive(STDIN_FILENO, se->buf))
			printf("\n"); /* TODO: do this only if interactive */

}
