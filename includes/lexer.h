#ifndef MINISHELL_LEXER_H
#define MINISHELL_LEXER_H

#include <string.h>

#include "error.h"

void lex(Error *err, char *source, char **beg, char **end);

#endif // MINISHELL_LEXER_H
