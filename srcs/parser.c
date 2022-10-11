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

    lexi = 0;
    pos = 1;
    i = 0;

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
            return PARSER_GET_EMPTY_LINE;
        }

        Token t;
        TokenType type;

        type = parser_get_token_type(lex);

        create_token(&t, type, pos, lex);
        add_token_list(l, t);
        printf("New token : %d %s\n", type, lex);

        // Check for end of input
        if (source[i] == '\0')
        {
            break;
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
    if (strcmp(buf, "ls") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "help") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "hello") == 0)
    {
        return FUNC;
    }
    if (strcmp(buf, "pwd") == 0)
    {
        return FUNC;
    }

    return (TokenType)-1;
}

TokenType parser_get_token_type(const char *buf)
{
    TokenType t;

    t = parser_get_func(buf);

    if (t == (TokenType)-1)
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

    return t;
}
