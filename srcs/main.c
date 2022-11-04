/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// main.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/16/37
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/main.h"

int main(void)
{
    char *input;
    char *path;
    Error err;

    err = ok;

    input = (char *)malloc(sizeof(char) * MAX_SIZE);

    path = (char *)malloc(sizeof(char) * MAX_SIZE);
    getcwd(path, MAX_SIZE);

    while (1 && err.type == ERROR_NONE)
    {
        int s;
		t_list_t buf_t;

		create_token_list(&err, &buf_t, 1);

        printf(">>");
        fgets(input, MAX_SIZE, stdin);

        s = parse_expr(&err, &buf_t, input);
        print_error(err);

		f_exec(&err, &buf_t);
		
		destroy_token_list(&err, &buf_t);

        if (!s)
        {
            break;
        }
    }

    free(path);
    free(input);
    return 0;
}
