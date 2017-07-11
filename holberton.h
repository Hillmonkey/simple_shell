#ifndef HOLBER_H
#define HOLBER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "$ "
#define BUFSIZE 1024
#define TRUE 1
#define FALSE 0
#define DELIM "\t\r\n "

/*macros for error switch*/
#define ERROR_MALLOC "Unable to malloc space\n"
#define ERROR_FORK "Unable to fork and create child process\n"
#define ERROR_PATH "No such file or directory\n"

extern char **environ;



char *_getline(FILE *fp);



/*helper functions*/
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);








#endif /* HOLBER_H */
