#ifndef MINISHELL_COLORS_H
#define MINISHELL_COLORS_H

#include <stdio.h>

void reset();

void red();
void red_string(char *s);

void blue();
void blue_string(char *s);

void red_bg();
void blue_bg();

#endif // MINISHELL_COLORS_H
