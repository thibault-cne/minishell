#ifndef MINISHELL_FUNCTIONS_F_EXEC_H
#define MINISHELL_FUNCTIONS_F_EXEC_H

#include <string.h>
#include <stdio.h>

#include "f_pwd.h"
#include "../token.h"

#ifdef __functions
const char *f_name[] = {"pwd", NULL};

void (*__f[])(Error *) = {f_pwd};
#endif

void f_exec(Error *err, t_list_t *token_list);

#endif // MINISHELL_FUNCTIONS_F_EXEC_H
