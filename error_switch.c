#include "holberton.h"
/**
** errors - writes error depending on the case letter
** @error_msg: error letter that goes with perror message
** Return: void
**/

void errors(char error_msg)
{

   /* local variable definition */

	switch (error_msg)
	{
	case 'A':
		write(STDERR_FILENO, ERROR_FORK, _strlen(ERROR_FORK));
		perror("Error");
		break;

	case 'B':
		perror("Error");
		break;

	case 'C':
		write(STDERR_FILENO, ERROR_MALLOC, _strlen(ERROR_FORK));
		break;


	case 'D':
		write(STDERR_FILENO, ERROR_PATH, _strlen(ERROR_PATH));
		break;

	default:
		return;
	}

}
