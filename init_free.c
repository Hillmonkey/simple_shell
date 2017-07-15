#include "holberton.h"

void init_env(shenv_t *shell_env)
{
	/* shell_env->pid = DUD */
	shell_env->status = 0;
	shell_env->linebuf = NULL;
	shell_env->linelen = 0;
	shell_env->linesize = 0;
	/* get rid of shell_env->my_argv[] later */
}
