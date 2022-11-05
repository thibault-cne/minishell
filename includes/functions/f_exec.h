#ifndef MINISHELL_FUNCTIONS_F_EXEC_H
#define MINISHELL_FUNCTIONS_F_EXEC_H

#include <string.h>
#include <stdio.h>

#include "f_pwd.h"
#include "f_exit.h"
#include "../token.h"

#ifdef __functions
const char *f_name[] = {"pwd", "exit", NULL};

void (*__f[])(Error *, t_list_t *, char *) = {f_pwd, f_exit};
#endif

void f_exec(Error *err, t_list_t *token_list, char *input);

#endif // MINISHELL_FUNCTIONS_F_EXEC_H
