/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   f_pwd.c                                                                  */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/05 17:50:00 by Thibault Cheneviere                      */
/*   Updated: 2022/11/05 17:50:01 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/functions/f_pwd.h"

void f_pwd(Error *err, t_list_t *tl, char *input)
{
	(void)tl;
	(void)input;
	char *path;
	
	path = (char *)malloc(sizeof(char) * PATH_MAX);

	if (!path) { ERROR_PREP(*err, ERROR_MALLOC, "Error while allocating the path variable."); return; }
	
	getcwd(path, PATH_MAX);

    printf("%s\n", path);

	free(path);
}
