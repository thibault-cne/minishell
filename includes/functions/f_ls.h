#ifndef MINISHELL_F_LS_H
#define MINISHELL_F_LS_H

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../token.h"
#include "../error.h"

void f_ls(Error *err, t_list_t *token_list, char *source);
int f_ls_check_path(const char *path);
void f_ls_display_rec(const char *path);

#endif // MINISHELL_F_LS_H
