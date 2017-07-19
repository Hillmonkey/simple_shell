#include "holberton.h"

int copy_into_strbuf(char buf[], int bufsize, char *src)
{
	int i;

	i = 0;

	if (bufsize <= 0 || !src)
		return (EXIT_FAILURE);

	while (i < bufsize && src[i])
	{
		buf[i] = src[i];
		i++;
	}

	if (i = bufsize && src[i])
	{
		perror("copy_into_strbuf: buffer_overflow");
		_exit;
	}
	else
		return (EXIT_SUCCESS);
}
