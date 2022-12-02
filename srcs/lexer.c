/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lexer.c                                                                  */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:50:18 by Thibault Cheneviere                      */
/*   Updated: 2022/12/03 00:00:25 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void lex(Error *err, char *source, char **beg, char **end) {
	const char *whitespaces = " \r\n";
	const char *delimiters = " \r\n";

	if (!source || !beg || !end) {
		ERROR_PREP(*err, ERROR_ARGUMENTS, "Invalid arguments");
		return;
	}

	*beg = source;
	*beg += strspn(*beg, whitespaces);

	if (*beg[0] == '"') {
		*beg += 1;
		*end = *beg;
		*end += strcspn(*beg, "\"");
		return;
	}

	*end = *beg;
	*end += strcspn(*beg, delimiters);
}
