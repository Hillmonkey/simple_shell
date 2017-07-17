#include "holberton.h"

/**
 * init_env - Initialize environment struct
 * @se: pointer to struct that holds vars for passing to functions
 **/

void init_env(shenv_t *se)
{
	/* se->pid = DUD */
	se->status = 0;
	se->linebuf = NULL;
	se->linelen = 0;
	se->linesize = 0;
	se->counter = 0;
	/* get rid of se->my_argv[] later */
}
