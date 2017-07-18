#include "holberton.h"

/**
 * absolute_path - returns boolean indicating of path string
 *                 started with '/', thus being absolute
 * @se: pointer to shell environment struct
 * Return: 1 if TRUE, 0 if FALSE, -1 if ERROR
 **/

int absolute_path(shenv_t *se)
{
	if (se->path_tokens && se->path_tokens[0])
		if (se->path_tokens[0][0] == '/')
			return (TRUE);
		else
			return (FALSE);
	else
		return (-1);
}

/**
 * main - simple shell, modelled after /bin/sh
 * @ac: number of passed in args
 * @av: array of args (strings) passed into main
 * Return: -1 on getline error, else # of commands executed by shell
 **/

int main(int ac, char **av)
{
	/* char *my_argv[2]; */
	shenv_t se;
	int not_builtin;

	UNUSED(ac);
	UNUSED(av);
	init_env(&se);
	do {
		prompt(STDIN_FILENO, se.buf);
		se.linelen = getline(&(se.linebuf), &(se.linesize), stdin);
		tokenize(&se);
		not_builtin = execute_builtin(&se);
		if (not_builtin)
		{
			if (absolute_path(&se))
				exec_cmd(&se);
			else
			{ /* build path array */
				if (get_path(&se) == EXIT_SUCCESS)
					printf("woo hoo!!! I wanna execute this: ");
					printf("%s\n", se.full_path);
			}
		}	
	} while (se.linelen > 0); /* linelen= 18446744073709551615 ??? */
	/* printf("linelen = %lu\n", linelen); */
	free(se.linebuf);
	se.linebuf = NULL;
	if (se.linelen == -1)
		return (-1);
	else
		return (se.counter);
}
