/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_ls.c                                                                   */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 20:21:38 by Thibault Cheneviere                      */
/*   Updated: 2022/12/04 19:09:31 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_ls.h"

void f_ls(Error *err, t_list_t *token_list, char *source) {
	(void)source;
	token_t *t;
	int flags;

	t = get_token_list(err, token_list, token_list->ptr - 1);
	flags = ft_ls_get_opt(err, token_list);

	if (!f_ls_check_path((const char *)t->value) && f_ls_has_path(token_list)) 
		ERROR_PREP(*err, ERROR_EXEC, "Invalid path : %s")

	if (err->type != ERROR_NONE)
		return;

	if (t->type == TOKEN_PARAMETER)
		f_ls_display_rec((const char *)t->value, flags);
	else
		f_ls_display_rec(".", flags); 
	


	putchar('\n');
}

void f_ls_display_rec(const char *path, int flags) {
	DIR *dir;
	struct dirent *entry;
	int tab;

	dir = opendir(path);
	tab = 0;
	
	while((entry = readdir(dir))) {
		char *new_path;
		int d_display;

		new_path = (char *)malloc(sizeof(char) * strlen(path) + strlen(entry->d_name) + 2);
		snprintf(new_path, strlen(path) + strlen(entry->d_name) + 2, "%s/%s", path, entry->d_name);

		d_display = ft_ls_display(entry, new_path, flags, tab);

		if (d_display)
			tab = 1;

		free(new_path);
	}

	closedir(dir);
}

