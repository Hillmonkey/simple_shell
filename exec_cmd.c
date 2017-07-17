#include "holberton.h"
/**
** exec_cmd - executes commands
** @se: arg
** Return: void
**/
void exec_cmd(shenv_t *se)
{
	char alpha_counter[30];

	tokenize(se);
	(se->counter)++;
	if (se->linelen > 0)
	{
		switch (se->pid = fork())
		{
			case -1:
				errors(1);
			case 0: /* child */
				se->status = execve(se->cmd_tokens[0], se->cmd_tokens, NULL);
				_puts(STDERR_FILENO, "hsh: ");
				itoa(se->counter, alpha_counter);
				_puts(STDERR_FILENO, alpha_counter);
				perror("");
				exit(se->status);
				/* errors(1); */
			default: /* parent */
				if (waitpid(se->pid, &(se->status), 0) < 0)
				{
					errors(1);
					exit(EXIT_FAILURE);
				}
		}
	}
	else if (is_interactive(STDIN_FILENO, se->buf))
		printf("\n");
}
