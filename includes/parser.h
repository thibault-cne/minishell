#ifndef MINISHELL_PARSER_H
#define MINISHELL_PARSER_H

#include <string.h>
#include <stdio.h>

#include "token.h"

enum _ParserStatus
{
    PARSER_SUCCESS,
    PARSER_ERROR,
    PARSER_SYNTAX_ERROR,
    PARSER_GET_EMPTY_LINE,
};
typedef enum _ParserStatus ParserStatus;

ParserStatus parser_start(TokenList *l, const char *source);

TokenType parser_get_func(const char *buf);
TokenType parser_get_token_type(const char *buf);

#endif // MINISHELL_PARSER_H
