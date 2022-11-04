/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// f_exec.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 22/55/30
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#define __functions

#include "../../includes/functions/f_exec.h"

void f_exec(Error *err, t_list_t *tl) {
	token_t *t_func;
	int i;

	t_func = get_token_list(err, tl, 0);

	i = -1;

	while (f_name[++i]) {
		if (!strcmp(f_name[i], t_func->value)) {
				printf("Found\n"); 
		}
	}
}
