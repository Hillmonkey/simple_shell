#ifndef HOLBER_H
#define HOLBER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define UNUSED(x) (void)(x)
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

/* helper1.c */
int _strcmp(char *s1, char *s2);
int str_eval(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);

/* helper2.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int init_char_buffer(char *buffer, int bufsize);
int init_Cptr_buffer(char **buffer, int bufsize);

/* error_switch.c */
void errors(char error_msg);

/* helper3.c */
/* int prompt(struct stat buf); */
int prompt(int fd, struct stat buf);
char **tokenize(char **str, char **tokens);

#endif /* HOLBER_H */
