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
 * struct shenv - shell environment variables
 * @pid: process id
 * @linebuf: obtained by getline
 * @av: argv passed into main (copy or original?)
 * @cmd_tokens: this will contain array of strings, like *argv[]
 * @path: a copy of path from environ or envp
 * @path_tokens: array of pointers to tokens in path
 * @full_path: concat of path, slash, and executable file
 * @linelen: line length return val of getline
 * @linesize: receives allocated size from getline
 * @status: status to exit with
 * @counter: number of lines executed by shell (returned on exit??)
 * @buf: exists to pass to pass to fstat
 **/

typedef struct shenv
{
	pid_t pid;
	char *linebuf;
	char **av;
	char *cmd_tokens[BUFSIZE];
	char *path;
	char **path_tokens;
	char *full_path;
	ssize_t linelen;
	size_t linesize;
	/* char *my_argv[2]; */
	int status;
	int counter;

	struct stat buf;
	} shenv_t;

typedef struct built_s
{
	char *name;
	
	int (p)();

}built_t;

/*builtins*/
int execute_builtin(char **args);
int built_exit(char **args);
int built_env(char **args);
int number_builtins(built_t built_in[]);



/* exec_cmd.c */
void exec_cmd(shenv_t *se);

/* helper1.c */
int _strcmp(char *s1, char *s2);
int str_eval(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void print_argv(char **argv);

/* helper2.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int init_char_buffer(char *buffer, int bufsize);
int init_Cptr_buffer(char **buffer, int bufsize);
void tokenize(shenv_t *se);

/* error_switch.c */
void errors(char error_msg);

/* init_free.c */
void init_env(shenv_t *shell_env);

/* math_helper.c */
int itoa(int n, char s[]);
int _abs(int n);

/* prompt.c */
void prompt(int fd, struct stat buff);
void _puts(char *str);
void _puts_err(char *str);
int is_interactive(int fd, struct stat buff);

/* helper3.c */
/* int prompt(int fd, struct stat buf); */
/* char **tokenize(char **str, char **tokens); */

#endif /* HOLBER_H */
