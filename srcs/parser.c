/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// parser.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 18/26/34
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../includes/parser.h"

int parse_expr(Error *err, t_list_t *tl, char *source)
{
    (void)tl;
    char *beg;
    char *end;
	int pos;
    int s;

    beg = source;
    end = source;

	pos = 1;
    s = 1;

    while (err->type == ERROR_NONE)
    {
        char *temp;
		token_t t;

        lex(err, beg, &beg, &end);

        if (beg == end)
        {
            break;
        }

        temp = (char *)malloc(sizeof(char) * (end - beg + 1));
        strncpy(temp, beg, (int)(end - beg));
        temp[end - beg] = '\0';
        printf("Token: %s\n", temp);
		
		if (pos == 1) { create_token(err, &t, temp, TOKEN_FUNC); }
		else { create_token(err, &t, temp, TOKEN_ARGUMENT); }

		add_token_list(err, tl, t);

        // Check if a token is equal to "exit"
        if (!strcmp(temp, "exit")) { s = 0; }

        beg = end;

		if (beg[0] == '"') {
			beg += 1;
		}

        free(temp);
		destroy_token(err, &t);
    }

    return s;
}
