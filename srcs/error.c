/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// error.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/31/48
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/error.h"

Error ok = {ERROR_NONE, NULL};

void print_error(Error err)
{
    if (err.type == ERROR_NONE)
    {
        return;
    }
    printf("ERROR: ");
    switch (err.type)
    {
    default:
        printf("Unkown error type...");
        break;
    case ERROR_ARGUMENTS:
        printf("Invalid arguments");
        break;
    }
    putchar('\n');
    if (err.msg)
    {
        printf("     : %s\n", err.msg);
    }
}
