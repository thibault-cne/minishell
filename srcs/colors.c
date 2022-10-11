/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// colors.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/11 14/32/04
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/colors.h"

void reset()
{
    printf("\033[0m");
}

void red()
{
    printf("\033[31m");
}
void red_string(char *s)
{
    red();
    printf("%s", s);
    reset();
}

void blue()
{
    printf("\033[34m");
}
void blue_string(char *s)
{
    blue();
    printf("%s", s);
    reset();
}

void red_bg()
{
    printf("\033[41m");
}
void blue_bg()
{
    printf("\033[44m");
}
