/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:50:38 by Thibault Cheneviere                      */
/*   Updated: 2022/12/03 00:02:57 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void parse_expr(Error *err, t_list_t *tl, char *source) {
	(void)tl;
	char *beg;
	char *end;
	int pos;

	beg = source;
	end = source;

	pos = 1;

	while (err->type == ERROR_NONE) {
		char *temp;
		token_t t;

		lex(err, beg, &beg, &end);

		if (beg == end)
            break;

		temp = (char *)malloc(sizeof(char) * (end - beg + 1));
		strncpy(temp, beg, (int)(end - beg));
		temp[end - beg] = '\0';
		
		if (pos == 1)
			create_token(err, &t, temp, TOKEN_FUNC);
		else { 
			if (temp[0] == '-')
				create_token(err, &t, temp, TOKEN_OPTION);
			else
				create_token(err, &t, temp, TOKEN_PARAMETER);
		}

		add_token_list(err, tl, t);

		beg = end;

		if (beg[0] == '"')
			beg += 1;

		pos++;
		
		free(temp);
		destroy_token(err, &t);
	}
}
