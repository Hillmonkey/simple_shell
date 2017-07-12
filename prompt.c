#include holberton.h
/**
**prompt - interactive or non interactive
**@fd: stream
**@buffer: buffer
**Return: void
**/
void prompt(int fd, struct stat buff)
{
	fstat(fd, &buff);

	if (S_ISCHR(buff.st_mode))
		_puts(PROMPT);
}
/**
 *_puts - function returns the length of a string.
 *@str: variable
 *Return: char
**/
void _puts(char *str)
{
	unsigned int len;

	len = _strlen(str);

	write(stderr, str, len);

}
