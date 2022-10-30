/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// main.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/16/37
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/main.h"

int main(void)
{
    char *input;
    Error err;

    err = ok;

    input = (char *)malloc(sizeof(char) * MAX_SIZE);

    while (1 && err.type == ERROR_NONE)
    {
        int s;

        printf(">>");
        fgets(input, MAX_SIZE, stdin);

        s = parse_expr(&err, input);
        print_error(err);

        if (!s)
        {
            break;
        }
    }

    free(input);
    return 0;
}
