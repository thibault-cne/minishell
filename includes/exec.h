#ifndef MINISHELL_EXEC_H
#define MINISHELL_EXEC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "token.h"

#define MAX_ARGS 100 // Max number of args and options to a function

enum _ExecStatus
{
    EXEC_SUCCESS,
    EXEC_ERROR,
};
typedef enum _ExecStatus ExecStatus;

struct _Exec
{
    ExecStatus status;
};
typedef struct _Exec Exec;

ExecStatus execution_start(TokenList *l);

int exec_get_related_args(TokenList *l, int index);
void exec_args(Exec *e, char *f[MAX_ARGS]);
void exec_func(Token *t);

#endif // MINISHELL_EXEC_H
