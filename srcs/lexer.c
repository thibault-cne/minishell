/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// lexer.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/23/31
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/lexer.h"

void lex(Error *err, char *source, char **beg, char **end)
{
    const char *whitespaces = " \r\n";
    const char *delimiters = " \r\n";

    if (!source || !beg || !end)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments");
        return;
    }

    *beg = source;
    *beg += strspn(*beg, whitespaces);
    *end = *beg;
    *end += strcspn(*beg, delimiters);
}
