#ifndef MINISHELL_PARSER_H
#define MINISHELL_PARSER_H

#include <stdio.h>

#include "error.h"
#include "lexer.h"

int parse_expr(Error *err, char *source);

#endif // MINISHELL_PARSER_H
