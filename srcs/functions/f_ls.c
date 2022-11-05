/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_ls.c                                                                   */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 20:21:38 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 21:31:07 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_ls.h"

void f_ls(Error *err, t_list_t *token_list, char *source) {
	(void)source;
	token_t *t;

	t = get_token_list(err, token_list, token_list->ptr - 1);

	if (!f_ls_check_path((const char *)t->value) && t->type == TOKEN_PARAMETER) {
		return;
	}

	if (t->type == TOKEN_PARAMETER) {
		f_ls_display_rec((const char *)t->value);
	} else {
		f_ls_display_rec("."); 
	}


	putchar('\n');
}

int f_ls_check_path(const char *path) {
    struct stat st;

    if (!stat(path, &st))
    {
        return S_ISDIR(st.st_mode);
    }

    return 0;
}

void f_ls_display_rec(const char *path) {
	DIR *dir;
	struct dirent *entry;
	int tab;

	dir = opendir(path);
	tab = 0;
	
	while((entry = readdir(dir))) {
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
			continue;
		}
		if (tab)
			putchar(' ');
		tab = 1;

		if (entry->d_type == DT_DIR) {
			f_printf("S|STYLE_BOLD|%s|S", entry->d_name);
		} else {
			f_printf(entry->d_name);
		}
	}

	closedir(dir);
}
