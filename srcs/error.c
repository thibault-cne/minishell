/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error.c                                                                  */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:50:09 by Thibault Cheneviere                      */
/*   Updated: 2022/12/02 23:48:16 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"

Error ok = {ERROR_NONE, NULL};

void print_error(Error err) {
	if (err.type == ERROR_NONE)
		return;

	printf("ERROR: ");
	switch (err.type) {
		default:
			printf("Unkown error type...");
			break;
		case ERROR_ARGUMENTS:
			printf("Invalid arguments");
			break;
		case ERROR_MALLOC:
			printf("Memory allocation failed");
			break;
		case ERROR_EXEC:
			printf("Error during execution");
			break;
	}
	putchar('\n');

	if (err.msg)
        printf("     : %s\n", err.msg);
}
