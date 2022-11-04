#ifndef MINISHELL_FUNCTIONS_F_PWD_H
#define MINISHELL_FUNCTIONS_F_PWD_H

#include <stdio.h>
#include <unistd.h>

#include "../error.h"

#define PATH_MAX 0x100

void f_pwd(Error *err);

#endif // MINISHELL_FUNCTIONS_F_PWD_H
