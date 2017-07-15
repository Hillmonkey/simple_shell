#include "holberton.h"

/**
 * main - simple shell, modelled after /bin/sh
 * Return: -1 on getline error, else # of commands executed by shell
 */

int main(int ac, char**av)
{
	pid_t pid;
	int status;
	int count = 0;
	ssize_t linelen = 0;
	size_t linesize = 0;
	/* char *linebuf = NULL; */
	char *my_argv[2];
	struct stat buf; /* ?? put in shell_env ?? */
	shenv_t shell_env;

	init_env(&shell_env);

	do {
		prompt(STDIN_FILENO, buf);
		linelen = getline(&(shell_env.linebuf), &(shell_env.linesize), stdin);
		my_argv[0] = strtok(shell_env.linebuf, DELIM);
		my_argv[1] = NULL;
		/* printf("linebuf = %s", linebuf); */
		if (linelen > 0)
		{
			switch (pid = fork())
			{
				case -1:
					perror("fork()");
				case 0: /* child */
					status = execve(my_argv[0], my_argv, NULL);
					exit(status);
				default: /* parent */
					if (waitpid(pid, &status, 0) < 0)
					{
						perror("waitpid()");
						exit(EXIT_FAILURE);
					}
			}
		}
		else
			printf("\n"); /* TODO: do this only if interactive */
	}while (shell_env.linelen > 0); /* linelen= 18446744073709551615 ??? */
	/* printf("linelen = %lu\n", linelen); */
	free(shell_env.linebuf);
	shell_env.linebuf = NULL;
	if (shell_env.linelen == -1)
		return (-1);
	else
		return (count);
}
