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
#include "../includes/exec.h"
#include "../includes/colors.h"

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

        ExecStatus estat = execution_start(&tokens);

        if (estat != EXEC_SUCCESS)
        {
            printf("Error during execution");
            return 1;
        }

        // Free all allocated memory
        destroy_token_list(&tokens);

        return 0;
    }

    char s[0x100];

    while (1)
    {
        TokenList tokens;

        create_token_list(&tokens, 1);
        red_string("shell > ");
        fgets(s, 0x100, stdin);

        ParserStatus pstat = parser_start(&tokens, s);

        if (pstat != PARSER_SUCCESS)
        {
            printf("Error during parsing.\n");
            return 1;
        }

        ExecStatus estat = execution_start(&tokens);

        if (estat != EXEC_SUCCESS)
        {
            printf("Error during execution");
            return 1;
        }

        // Destroy allocated memory to restart the next command.
        destroy_token_list(&tokens);
    }

    return 0;
}
