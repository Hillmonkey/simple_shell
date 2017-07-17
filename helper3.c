#include "holberton.h"

/**
 * prompt - prints prompt to stdout, but only in interactive mode
 * @fd: file descriptor (typically 1 for stdout)
 * @sb: the file stat struct (see man fstat)
 * Return: EXIT_SUCCESS
 **/

/*
int prompt(struct stat sb)
{
	if ((sb.st_mode & S_IFMT) != S_IFIFO)
		_puts(PROMPT);
	return (EXIT_SUCCESS);
}
*/

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
 * Return: zero for success
**/
/*
int prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
	return (EXIT_SUCCESS);
}
*/

/**
 * tokenize
 *
 *
 **/

/**
char **tokenize(char **str, char **tokens)
{
	int i;
	char *tmp;

	tmp = tokens[0] = strtok(*str, DELIM);
	for (i = 1; tmp; i++)
	{
		tokens[i] = tmp = strtok(NULL, DELIM);
	}
	return (tokens);
}
**/
