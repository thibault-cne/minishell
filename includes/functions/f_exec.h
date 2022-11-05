#ifndef MINISHELL_FUNCTIONS_F_EXEC_H
#define MINISHELL_FUNCTIONS_F_EXEC_H

#include <string.h>
#include <stdio.h>

#include "f_pwd.h"
#include "f_exit.h"
#include "f_echo.h"
#include "f_ls.h"
#include "../token.h"

#ifdef __functions
const char *f_name[] = {"pwd", "exit", "echo", "ls",  NULL};

void (*__f[])(Error *, t_list_t *, char *) = {f_pwd, f_exit, f_echo, f_ls};
#endif

void f_exec(Error *err, t_list_t *token_list, char *input);

#endif // MINISHELL_FUNCTIONS_F_EXEC_H
