#ifndef MINISHELL_TOKEN_H
#define MINISHELL_TOKEN_H

#include <stdlib.h>
#include <string.h>

#include "error.h"

enum _token_type {
	TOKEN_NONE = 0,
	TOKEN_FUNC,
	TOKEN_OPTION,
	TOKEN_PARAMETER,
    TOKEN_MAX,
};
struct _token {
    enum _token_type type;
    char *value;
};
typedef struct _token token_t;

void create_token(Error *err, token_t *t, char *value, enum _token_type type);
void destroy_token(Error *err, token_t *t);

struct _token_list {
    token_t *data;
    int ptr;
    int size;
};
typedef struct _token_list t_list_t;

void create_token_list(Error *err, t_list_t *tl, int size);
void add_token_list(Error *err, t_list_t *tl, token_t t);
token_t *get_token_list(Error *err, t_list_t *tl, int i);
void destroy_token_list(Error *err, t_list_t *tl);

#endif // MINISHELL_TOKEN_H
