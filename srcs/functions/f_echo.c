/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_echo.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:49:19 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 17:49:22 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_echo.h"

void f_echo(Error *err, t_list_t *token_list, char *input) {
	(void)input;

	int i;
	token_t *t;

	i = 0;

	while(++i < token_list->ptr) {
		t = get_token_list(err, token_list, i);
		printf("%s", t->value);

		if (i < token_list->ptr) {
			putchar(' ');
		}
	}

	putchar('\n');
}
