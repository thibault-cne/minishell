/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_ls_2.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/11 20:42:18 by Thibault Cheneviere                      */
/*   Updated: 2022/11/11 20:51:53 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_ls.h"

int ft_ls_get_opt(Error *err, t_list_t *tl) {
	int i;
	int opt;
	token_t *t;

	i = 0;
	opt = 0;

	while(++i < tl->ptr) {
		t = get_token_list(err, tl, i);

		if (t->type == TOKEN_OPTION)
			opt += ft_ls_get_opt_val(t->value);
	}

	return opt;
}

int ft_ls_get_opt_val(const char *flag) {
	int i;
	int val;

	i = -1;
	val = 0;

	while(flag[++i]) {
		if (flag[i] == 'a')
			val += __A_OPT;
		if (flag[i] == 'l')
			val += __L_OPT;
	}

	return val;
}

int f_ls_check_path(const char *path) {
    struct stat st;

    if (!stat(path, &st))
    {
        return S_ISDIR(st.st_mode);
    }

    return 0;
}
