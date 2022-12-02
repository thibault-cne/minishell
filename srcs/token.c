/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   token.c                                                                  */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:50:45 by Thibault Cheneviere                      */
/*   Updated: 2022/12/02 23:56:56 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/token.h"

void create_token(Error *err, token_t *t, char *tok_value, enum _token_type tok_type) {
	if (!t || !tok_value) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments in create_token");
		return;
	}

	t->type = tok_type;

	t->value = (char *)malloc(sizeof(char) * (strlen(tok_value) + 1));

	if (!t->value) {
		ERROR_PREP(*err, ERROR_MALLOC, "Malloc failed for token value");
		return;
	}
	strcpy(t->value, tok_value);
}

void destroy_token(Error *err, token_t *t) {
	if (!t) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for destroy_token");
		return;
	}

	free(t->value);
	t->value = NULL;
}

void create_token_list(Error *err, t_list_t *tl, int size) {
	if (!tl) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for create_token_list");
		return;
	}

	tl->size = size;
	tl->data = (token_t *)malloc(sizeof(token_t) * size);
	tl->ptr = 0;
	if (!tl->data) {
		ERROR_PREP(*err, ERROR_MALLOC, "Malloc failed for token_list");
		return;
	}
}

void add_token_list(Error *err, t_list_t *tl, token_t tok) {
	if (!tl) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for add_token_list");
		return;
    }

	if (tl->ptr >= tl->size) {
		tl->size *= 2;
		tl->data = (token_t *)realloc(tl->data, sizeof(token_t) * tl->size);
		if (!tl->data) {
			ERROR_PREP(*err, ERROR_MALLOC, "Realloc failed for token_list");
			return;
		}
	}

	token_t *t;
	t = &tl->data[tl->ptr++];

	create_token(err, t, tok.value, tok.type);
}

token_t *get_token_list(Error *err, t_list_t *tl, int i) {
	if (!tl) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for get_token_list");
		return NULL;
	}

	if (i >= tl->ptr) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Index out of bounds for get_token_list");
		return NULL;
	}

	return &tl->data[i];
}

void destroy_token_list(Error *err, t_list_t *tl) {
	if (!tl) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for destroy_token_list");
		return;
	}

	int i;
	i = -1;

	while(++i < tl->ptr)
		destroy_token(err, &tl->data[i]);

	free(tl->data);
	tl->data = NULL;
}
