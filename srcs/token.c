/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// token.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 19/08/57
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/token.h"

void create_token(Error *err, token *t, char *value, int type)
{
    if (!t || !value)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments in create_token");
        return;
    }

    t->type = type;

    t->value = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    if (!t->value)
    {
        ERROR_PREP(*err, ERROR_MALLOC, "Malloc failed for token value");
        return;
    }
    strcpy(t->value, value);
}

void destroy_token(Error *err, token *t)
{
    if (!t)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for destroy_token");
        return;
    }

    free(t->value);
    t->value = NULL;
}

void create_token_list(Error *err, token_list *tl, int size)
{
    if (!tl)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for create_token_list");
        return;
    }

    tl->size = size;
    tl->data = (token *)malloc(sizeof(token) * size);
    if (!tl->data)
    {
        ERROR_PREP(*err, ERROR_MALLOC, "Malloc failed for token_list");
        return;
    }
}

void add_token_list(Error *err, token_list *tl, token tok)
{
    if (!tl)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for add_token_list");
        return;
    }

    if (tl->ptr >= tl->size)
    {
        tl->size *= 2;
        tl->data = (token *)realloc(tl->data, sizeof(token) * tl->size);
        if (!tl->data)
        {
            ERROR_PREP(*err, ERROR_MALLOC, "Realloc failed for token_list");
            return;
        }
    }

    token *t;

    t = &tl->data[tl->ptr++];
    create_token(err, t, tok.value, tok.type);
}

token *get_token_list(Error *err, token_list *tl, int i)
{
    if (!tl)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for get_token_list");
        return NULL;
    }

    if (i >= tl->ptr)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Index out of bounds for get_token_list");
        return NULL;
    }

    return &tl->data[i];
}

void destroy_token_list(Error *err, token_list *tl)
{
    if (!tl)
    {
        ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments for destroy_token_list");
        return;
    }

    for (int i = 0; i < tl->ptr; i++)
    {
        destroy_token(err, &tl->data[i]);
    }
    free(tl->data);
    tl->data = NULL;
}