#ifndef MINISHELL_FUNCTIONS_F_PWD_H
#define MINISHELL_FUNCTIONS_F_PWD_H

#include <stdio.h>
#include <unistd.h>

#include "../error.h"
#include "../token.h"

#define PATH_MAX 0x100

void f_pwd(Error *err, t_list_t *tl, char *input);

#endif // MINISHELL_FUNCTIONS_F_PWD_H
