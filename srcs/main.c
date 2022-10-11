/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// main.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/11 08/22/43
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include <stdio.h>

#include "../includes/parser.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        TokenList tokens;

        create_token_list(&tokens, 1);

        ParserStatus pstat = parser_start(&tokens, argv[1]);

        if (pstat != PARSER_SUCCESS)
        {
            printf("Error during parsing.\n");
            return 1;
        }

        // Free all allocated memory
        destroy_token_list(&tokens);

        return 0;
    }

    return 0;
}
