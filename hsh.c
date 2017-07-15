#include "holberton.h"

/**
 * main - simple shell, modelled after /bin/sh
 * @ac: number of passed in args
 * @av: array of args (strings) passed into main
 * Return: -1 on getline error, else # of commands executed by shell
 */

int main(int ac, char **av)
{
	char *my_argv[2];
	shenv_t se;

	UNUSED(ac);
	UNUSED(av);
	init_env(&se);
	do {
		prompt(STDIN_FILENO, se.buf);
		se.linelen = getline(&(se.linebuf), &(se.linesize), stdin);
		my_argv[0] = strtok(se.linebuf, DELIM);
		my_argv[1] = NULL;
		/* printf("linebuf = %s", linebuf); */
		if (se.linelen > 0)
		{
			switch (se.pid = fork())
			{
				case -1:
					perror("fork()");
				case 0: /* child */
					se.status = execve(my_argv[0], my_argv, NULL);
					exit(se.status);
				default: /* parent */
					if (waitpid(se.pid, &(se.status), 0) < 0)
					{
						perror("waitpid()");
						exit(EXIT_FAILURE);
					}
			}
		}
		else
			printf("\n"); /* TODO: do this only if interactive */
	} while (se.linelen > 0); /* linelen= 18446744073709551615 ??? */
	/* printf("linelen = %lu\n", linelen); */
	free(se.linebuf);
	se.linebuf = NULL;
	if (se.linelen == -1)
		return (-1);
	else
		return (se.count);
}
