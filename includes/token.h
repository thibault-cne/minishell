#ifndef MINISHELL_TOKEN_H
#define MINISHELL_TOKEN_H

#include <stdlib.h>

#include "error.h"

struct _token
{
    enum _token_type
    {
        TOKEN_NONE = 0,
        TOKEN_FUNC,
        TOKEN_ARGUMENT,
        TOKEN_MAX,
    } type;
    char *value;
};
typedef struct _token token;

void create_token(Error *err, token *t, char *value, int type);
void destroy_token(Error *err, token *t);

struct _token_list
{
    Token *data;
    int ptr;
    int size;
};
typedef struct _token_list token_list;

void create_token_list(Error *err, token_list *tl, int size);
void add_token_list(Error *err, token_list *tl, token t);
token *get_token_list(Error *err, token_list *tl, int i);
void destroy_token_list(Error *err, token_list *tl);

#endif // MINISHELL_TOKEN_H
