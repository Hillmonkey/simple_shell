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

/**
 * shenv_t - shell environment variables
 * @linebuf: obtained by getline
 * @av: argv passed into main (copy or original?)
 * @path: a copy of path from environ or envp
 * @path_tokens: array of pointers to tokens in path
 * @full_path: concat of path, slash, and executable file
 * @linelen:
 * @linesize: receives allocated size from getline
 * @status: status to exit with
 * @count: number of lines executed by shell (returned on exit??)
 * @buf: exists to pass to pass to fstat
 **/

typedef struct shenv {
	pid_t pid;
	char *linebuf;
	char **av;
	char *path;
	char **path_tokens;
	char *full_path;
	ssize_t linelen;
	size_t linesize;
	/* char *my_argv[2]; */
	int status;
	int count;
	
	struct stat buf;
	} shenv_t;

/* exec_cmd.c */
void exec_cmd(shenv_t *se);

/* helper_functions.c */
int _strcmp(char *s1, char *s2);
int str_eval(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* helper2.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int init_char_buffer(char *buffer, int bufsize);
int init_Cptr_buffer(char **buffer, int bufsize);

/* error_switch.c */
void errors(char error_msg);

/* init_env.c */
void init_env(shenv_t *shell_env);

/* prompt.c */
void prompt(int fd, struct stat buff);
void _puts(char *str);
int is_interactive(int fd, struct stat buff);
#endif /* HOLBER_H */
