#include "holberton.h"

/**
 * main - super simple shell
 * Return: -1 on error status, 0 on normal execution
 */

int main(void)
{
	pid_t pid;
	int status;
	ssize_t linelen = 0;
	size_t linesize = 0;
	char **tokens;
	struct stat sb;
	char *linebuf = NULL;

	tokens = malloc(BUFSIZE * sizeof(char *));
	do {
		/* prompt(sb); */
		prompt(STDOUT_FILENO, sb);
		/* printf("($) "); */
		linelen = getline(&linebuf, &linesize, stdin);
		tokens = tokenize(&linebuf, tokens);
		if (linelen > 0)
		{
			switch (pid = fork())
			{
				case -1:
					perror("fork()");
				case 0: /* child */
					status = execve(tokens[0], tokens, NULL);
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
			printf("\n");
	} while (linelen > 0); /* linelen= 18446744073709551615 ??? */

	/* printf("linelen = %lu\n", linelen); */
	free(linebuf);
	linebuf = NULL;
	if (linelen == -1)
		return (-1);
	else
		return (0);
}
