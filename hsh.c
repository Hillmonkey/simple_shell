#include "holberton.h"

/**
 * main - simple shell, modelled after /bin/sh
 * @ac: number of passed in args
 * @av: array of args (strings) passed into main
 * Return: -1 on getline error, else # of commands executed by shell
 */

int main(int ac, char **av)
{
	/* char *my_argv[2]; */
	shenv_t se;

	UNUSED(ac);
	UNUSED(av);
	init_env(&se);
	do {
		prompt(STDIN_FILENO, se.buf);
		se.linelen = getline(&(se.linebuf), &(se.linesize), stdin);
		tokenize(&se);
		execute_builtin(&se);
		exec_cmd(&se);
	} while (se.linelen > 0); /* linelen= 18446744073709551615 ??? */
	/* printf("linelen = %lu\n", linelen); */
	free(se.linebuf);
	se.linebuf = NULL;
	if (se.linelen == -1)
		return (-1);
	else
		return (se.counter);
}
