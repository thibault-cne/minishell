/* ************************************************************************************************************ */
/*                                                                                                              */
/*                                                                                                              */
// f_pwd.c
/*                                                                                                              */
// by Thibault Cheneviere : thibault.cheneviere@telecomnancy.eu
/*                                                                                                              */
// Created : 2022/10/30 22/52/47
/*                                                                                                              */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include "../../includes/functions/f_pwd.h"

void f_pwd(Error *err)
{
	char *path;
	
	path = (char *)malloc(sizeof(char) * PATH_MAX);

	if (!path) { ERROR_PREP(*err, ERROR_MALLOC, "Error while allocating the path variable."); return; }
	
	getcwd(path, PATH_MAX);

    printf("%s\n", path);

	free(path);
}
