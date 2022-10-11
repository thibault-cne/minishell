#ifndef MINISHELL_TOKEN_H
#define MINISHELL_TOKEN_H

#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 0xFF // Max size of a token data

enum _TokenType
{
    FUNC,
    ARG,
    OPT,
    PIPE,
};
typedef enum _TokenType TokenType;

struct _Token
{
    int type;
    int pos;
    char data[MAX_SIZE];
};
typedef struct _Token Token;

void create_token(Token *t, int type, int pos, char *data);

struct _TokenList
{
    Token *data;
    int ptr;
    int size;
};
typedef struct _TokenList TokenList;

void create_token_list(TokenList *l, int size);
void add_token_list(TokenList *l, Token t);
Token *get_token_list(TokenList *l, int i);
void destroy_token_list(TokenList *l);

#endif // MINISHELL_TOKEN_H
