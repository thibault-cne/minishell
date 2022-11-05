#include "../../includes/functions/f_exit.h"


void f_exit(Error *err, t_list_t *token_list, char *input) {
	printf("Exiting minishell...\n");

	free(input);
	destroy_token_list(err, token_list);

	exit(0);
}
