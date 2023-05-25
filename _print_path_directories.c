#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "_printf.h"
/**
 * _print_path_directories - prints directories in the PATH variable
 */
void _print_path_directories(void)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *token = strtok(path_copy, ":");

	if (path == NULL)
		return;
	if (path_copy == NULL)
		return;
	while (token != NULL)
	{
		_printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	free(path_copy);
}
