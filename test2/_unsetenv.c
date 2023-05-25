#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name of the env variable
 * Return: Always 0
 */
int _unsetenv(const char *name)
{
	size_t name_length = __strlen(name);
	int i = 0, j, k;

	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] && environ[i][j] != '=' && environ[i][j] == name[j])
			j++;
		if (environ[i][j] == '=' && j == (int)name_length)
		{
			k = i;
			while (environ[k + 1])
			{
				environ[k] = environ[k + 1];
				k++;
			}
			environ[k] = NULL;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

