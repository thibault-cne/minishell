/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// exec.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/11 08/36/02
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/exec.h"

ExecStatus execution_start(TokenList *l)
{
    int i;
    Token *t;
    Exec e;

    i = -1;

    while (++i < l->ptr)
    {
        t = get_token_list(l, i);

        if (t->type == BULTIN)
        {
            int n;
            int fi;
            char *f[MAX_ARGS];

            fi = 0;
            n = exec_get_related_args(l, i);
            f[fi] = malloc(sizeof(char *) * MAX_SIZE);
            strncpy(f[fi], t->data, MAX_SIZE);

            while (++fi < n + 1)
            {
                t = get_token_list(l, fi + i);

                if (t->type != ARG && t->type != OPT)
                {
                    return EXEC_ERROR;
                }
                f[fi] = malloc(sizeof(char *) * MAX_SIZE);
                strncpy(f[fi], t->data, MAX_SIZE);
            }
            f[fi] = NULL;
            e.status = EXEC_SUCCESS;
            exec_args(&e, f);

            fi = 0;
            free(f[fi]);
            while (++fi < n + 1)
            {
                free(f[fi]);
            }

            if (e.status != EXEC_SUCCESS)
            {
                return e.status;
            }

            i += n;
        }

        if (t->type == FUNC)
        {
            exec_func(t);
        }
    }

    return EXEC_SUCCESS;
}

int exec_get_related_args(TokenList *l, int index)
{
    int i;
    int cpt;
    Token *t;

    i = index;
    cpt = 0;

    while (++index < l->ptr)
    {
        t = get_token_list(l, index);
        if (t->type != ARG && t->type != OPT)
        {
            break;
        }
        cpt++;
        i++;
    }

    return cpt;
}

void exec_args(Exec *e, char *f[MAX_ARGS])
{
    // Forking a child
    pid_t pid = fork();

    if (pid == -1)
    {
        e->status = EXEC_ERROR;
        return;
    }
    if (pid == 0)
    {
        if (execvp(f[0], f) < 0)
        {
            e->status = EXEC_ERROR;
        }
        exit(0);
    }
    else
    {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}

void exec_func(Token *t)
{
    if (strcmp(t->data, "exit") == 0)
    {
        exit(0);
    }
}
