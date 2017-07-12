#include "holberton.h"

/**
 * prompt - prints prompt to stdout, but only in interactive mode
 * @fd: file descriptor (typically 1 for stdout)
 * Return: EXIT_SUCCESS
 **/

int prompt(int fd)
{
	if (isatty(fd))
		_puts(PROMPT);
	return (EXIT_SUCCESS);
}
