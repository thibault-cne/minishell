/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_exit.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:49:02 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 17:49:08 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_exit.h"


void f_exit(Error *err, t_list_t *token_list, char *input) {
	printf("Exiting minishell...\n");

	free(input);
	destroy_token_list(err, token_list);

	exit(0);
}
