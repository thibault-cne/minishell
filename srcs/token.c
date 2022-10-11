/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// token.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/10 22/37/09
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/token.h"

void create_token(Token *t, int type, int pos, char *data)
{
    t->type = type;
    t->pos = pos;
    strncpy(t->data, data, MAX_SIZE);
}

void create_token_list(TokenList *l, int size)
{
    l->data = (Token *)malloc(sizeof(Token) * size);
    l->ptr = 0;
    l->size = size;
}

void add_token_list(TokenList *l, Token tok)
{
    if (l->ptr >= l->size)
    {
        l->size *= 2;
        l->data = (Token *)realloc(l->data, sizeof(Token) * l->size);
    }

    Token *t = &l->data[l->ptr++];
    create_token(t, tok.type, tok.pos, tok.data);
}

Token *get_token_list(TokenList *l, int i)
{
    if (i >= l->size)
    {
        return NULL;
    }

    return &l->data[i];
}

void destroy_token_list(TokenList *l)
{
    free(l->data);
}
