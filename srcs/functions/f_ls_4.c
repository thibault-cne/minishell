/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_ls_4.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/12/04 19:10:02 by Thibault Cheneviere                      */
/*   Updated: 2022/12/04 19:12:40 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_ls.h"

int f_ls_has_path(t_list_t *token_list) {
	token_t *t;
	int i;

	i = -1;

	while(++i < token_list->ptr) {
		t = get_token_list(NULL, token_list, i);

		if (t->type == TOKEN_PARAMETER)
			return 1;
	}

	return 0;
}
