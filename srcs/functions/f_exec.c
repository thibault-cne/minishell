/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_exec.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:49:41 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 21:17:45 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#define __functions

#include "../../includes/functions/f_exec.h"

void f_exec(Error *err, t_list_t *tl, char *input) {
	token_t *t_func;
	int i;

	t_func = get_token_list(err, tl, 0);

	i = -1;

	while (f_name[++i]) {
		if (!strcmp(f_name[i], t_func->value)) {
				__f[i](err, tl, input);
		}
	}
}
