#ifndef MINISHELL_F_ECHO_H
#define MINISHELL_F_ECHO_H

#include <stdio.h>

#include "../error.h"
#include "../token.h"

void f_echo(Error *err, t_list_t *token_list, char *input);

#endif // MINISHELL_F_ECHO_H
