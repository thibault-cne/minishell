/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// parser.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/10 22/51/16
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/parser.h"

ParserStatus parser_start(TokenList *l, const char *source)
{
    char lex[0x100];
    int lexi;
    int i;
    int pos;
    int isFunc;

    lexi = 0;
    pos = 1;
    i = 0;

    isFunc = 1;

    while (1)
    {
        while (source[i] != ' ' && source[i] != '\t' && source[i] != '\n' && source[i] != '\0')
        {
            lex[lexi++] = source[i++];
        }

        // Append an end of string delimiter to the lexical buffer
        lex[lexi] = '\0';

        // Check for empty line
        if (lexi == 0)
        {
            break;
        }

        Token t;
        TokenType type;

        if (isFunc == 1)
        {
            type = parser_get_func(lex);

            if (type == (TokenType)-1)
            {
                type = BULTIN;
            }

            isFunc = 0;
        }
        else
        {
            type = parser_get_token_type(lex);
        }

        create_token(&t, type, pos, lex);
        add_token_list(l, t);
        // Check for end of input
        if (source[i] == '\0')
        {
            break;
        }

        // If we have a pipe, next token is a function
        if (source[0] == '|')
        {
            isFunc = 1;
        }

        // Increment pos
        pos++;

        // Reset i and lexi index
        lexi = 0;
        i++;
    }

    return PARSER_SUCCESS;
}

TokenType parser_get_func(const char *buf)
{
    if (strcmp(buf, "help") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "hello") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "exit") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "cd") == 0)
    {
        return FUNC;
    }

    return (TokenType)-1;
}

TokenType parser_get_token_type(const char *buf)
{
    if (buf[0] == '-')
    {
        return OPT;
    }
    if (buf[0] == '|')
    {
        return PIPE;
    }

    return ARG;
}
