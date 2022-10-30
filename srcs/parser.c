/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// parser.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/26/34
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/parser.h"

int parse_expr(Error *err, char *source)
{
    char *beg;
    char *end;
    int s;

    beg = source;
    end = source;

    s = 1;

    while (err->type == ERROR_NONE)
    {
        lex(err, beg, &beg, &end);

        if (beg == end)
        {
            break;
        }

        printf("Token: %.*s\n", (int)(end - beg), beg);

        // Check if a token is equal to "exit"
        if (!strncmp(beg, "exit", end - beg))
        {
            s = 0;
        }

        beg = end;
    }

    return s;
}
