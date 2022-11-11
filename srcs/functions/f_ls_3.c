/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_ls_3.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/11 20:59:10 by Thibault Cheneviere                      */
/*   Updated: 2022/11/11 21:33:24 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_ls.h"

int ft_ls_display(struct dirent *entry, const char *path, int flags, int tab) {
	int d_display = 0;

	if (tab)
		putchar(' ');

	if (flags == __NULL_OPT && entry->d_name[0] != '.') {
		d_display = 1;
		ft_ls_display_line(entry);
	}
	if (flags == __A_OPT) {
		d_display = 1;
		ft_ls_display_line(entry);
	}
	if (flags == __L_OPT && entry->d_name[0] != '.')
		ft_ls_display_l(entry, path);
	if (flags == __AL_OPT)
		ft_ls_display_l(entry, path);

	return d_display;
}

void ft_ls_display_line(struct dirent *entry) {
	if (entry->d_type == DT_DIR) {
		f_printf("S|STYLE_BOLD|%s|S", entry->d_name);
	} else {
		f_printf(entry->d_name);
	}
}

void ft_ls_display_l(struct dirent *entry, const char *path) {
	ft_putperm(path);
	ft_ls_display_line(entry);

	putchar('\n');
}

void ft_putperm(const char *path) {
	struct stat st;
	
	if (stat(path, &st) < 0)
		return;

	if (S_ISDIR(st.st_mode))
		putchar('d');
	else
		putchar('-');
	if (st.st_mode & S_IROTH)
		putchar('r');
	else
		putchar('-');
	if (st.st_mode & S_IWOTH)
		putchar('w');
	else
		putchar('-');
	if (st.st_mode & S_IXOTH)
		putchar('x');
	else
		putchar('-');
	if (st.st_mode & S_IRGRP)
		putchar('r');
	else
		putchar('-');
	if (st.st_mode & S_IWGRP)
		putchar('w');
	else
		putchar('-');
	if (st.st_mode & S_IXGRP)
		putchar('x');
	else
		putchar('-');
	if (st.st_mode & S_IRUSR)
		putchar('r');
	else
		putchar('-');
	if (st.st_mode & S_IWUSR)
		putchar('w');
	else
		putchar('-');
	if (st.st_mode & S_IXUSR)
		putchar('x');
	else
		putchar('-');

	putchar(' ');
}
