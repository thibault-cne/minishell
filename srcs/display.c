/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   display.c                                                                */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 21:23:54 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 21:30:08 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#define __styles

#include "../includes/display.h"

char *f_sprintf(const char *format, va_list args)
{
    va_list args2;
    size_t len;

    va_copy(args2, args);

    len = vsnprintf(NULL, 0, format, args);
    char *str = (char *)malloc((len + 1) * sizeof(char));

    vsnprintf(str, len + 1, format, args2);

    va_end(args);

    str[len] = '\0';
    return str;
}

void f_printf(const char *format, ...)
{
    va_list args;
    char *str;
    char *beg;
    char *end;
    char *whitespace;
    char *delimiters;

    va_start(args, format);
    str = f_sprintf(format, args);
    va_end(args);

    beg = str;
    end = str;

    whitespace = " \t";
    delimiters = "|";

    while (*end != '\0')
    {
        beg += strspn(beg, whitespace);
        end = beg + strcspn(beg, delimiters);
        f_cprintf(&beg, &end);

        beg = end + 1;
    }

    free(str);
}

void f_cprintf(char **beg, char **end)
{
    char *format;
    int i;

    format = malloc(sizeof(char) * (*end - *beg + 1));
    strncpy(format, *beg, *end - *beg);
    format[(int)(*end - *beg)] = '\0';

    i = -1;

    while (styles[++i])
    {
        if (strcmp(format, styles[i]) == 0)
        {
            printf("%s", converted_styles[i]);
            free(format);
            return;
        }
    }

    printf("%s", format);
    free(format);
}
