#ifndef MINISHELL_ERROR_H
#define MINISHELL_ERROR_H

#define ERROR_PREP(n, t, message) \
    (n).type = (t);               \
    (n).msg = (message);

#include <stdio.h>
#include <stdlib.h>

typedef struct _Error
{
    enum _ErrorType
    {
        ERROR_NONE = 0,
        ERROR_ARGUMENTS,
        ERROR_MALLOC,
		ERROR_EXEC,
        ERROR_MAX,
    } type;
    char *msg;
} Error;

extern Error ok;

void print_error(Error err);

#endif // MINISHELL_ERROR_H
