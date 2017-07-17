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
				perror("fork()");
			case 0: /* child */
				se->status = execve(se->cmd_tokens[0], se->cmd_tokens, NULL);
				if (_strlen(se->cmd_tokens[0]) > 0)
				{
					_puts_err("hsh: ");
					itoa(se->counter, alpha_counter);
					_puts_err(alpha_counter);
					_puts_err(": ");
					_puts_err(se->cmd_tokens[0]);
					perror(" ");
					exit(se->status);
				}
			default: /* parent */
				if (waitpid(se->pid, &(se->status), 0) < 0)
				{
					perror("waitpid()");
					exit(EXIT_FAILURE);
				}
		}
	}
	else if (is_interactive(STDIN_FILENO, se->buf))
		printf("\n");
}