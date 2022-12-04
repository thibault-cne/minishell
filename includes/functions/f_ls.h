#ifndef MINISHELL_F_LS_H
#define MINISHELL_F_LS_H

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../token.h"
#include "../error.h"
#include "../display.h"

#define __NULL_OPT 0
#define __A_OPT 1
#define __L_OPT 2
#define __AL_OPT 3

void f_ls(Error *err, t_list_t *token_list, char *source);
void f_ls_display_rec(const char *path, int flags);

int ft_ls_get_opt(Error *err, t_list_t *tl);
int ft_ls_get_opt_val(const char *flag);
int f_ls_check_path(const char *path);

int ft_ls_display(struct dirent *entry, const char *path, int flags, int tab);
void ft_ls_display_line(struct dirent *entry);
void ft_ls_display_l(struct dirent *entry, const char *path);
void ft_putperm(const char *path);

int f_ls_has_path(t_list_t *token_list);

#endif // MINISHELL_F_LS_H
