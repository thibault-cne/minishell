#ifndef MINISHELL_FUNCTIONS_F_EXIT_H
#define MINISHELL_FUNCTIONS_F_EXIT_H

#include <stdlib.h>
#include <stdio.h>

#include "../error.h"
#include "../token.h"

void f_exit(Error *err, t_list_t *token_list, char *input);

#endif // MINISHELL_FUNCTIONS_F_EXIT_H
