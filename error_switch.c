#include "holberton.h"
/**
** errors - writes error depending on the case letter
** @error_msg: error letter that goes with perror message
** Return: void
**/

void errors(int error_msg)
{

   /* local variable definition */

	switch (error_msg)
	{
	case 1:
		write(STDERR_FILENO, ERROR_FORK, _strlen(ERROR_FORK));
		perror("Error");
		break;

	case 2:
		perror("Error");
		break;

	case 3:
		write(STDERR_FILENO, ERROR_MALLOC, _strlen(ERROR_MALLOC));
		break;


	case 4:
		write(STDERR_FILENO, ERROR_PATH, _strlen(ERROR_PATH));
		break;

	default:
		return;
	}

}
