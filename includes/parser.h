#ifndef MINISHELL_PARSER_H
#define MINISHELL_PARSER_H

#include <stdio.h>

#include "error.h"
#include "lexer.h"
#include "token.h"

void parse_expr(Error *err, t_list_t *tl, char *source);

#endif // MINISHELL_PARSER_H
