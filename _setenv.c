#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _setenv -  Adds an env variable
 * @name: Name of env variable
 * @value: value of env variable
 * @overwrite: overwrite env variable
 * Return: Always 0
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_length = __strlen(name), value_length = __strlen(name);
	int i = 0, j = 0;
	char *entry = malloc(name_length + value_length + 2), *p = entry;
	char **new_environ = malloc((i + 2) * sizeof(char *));

	if (!name || !value)
		return (-1);
	while (environ[i])
	{
		while (environ[i][j] == name[j] && name[j] != '=')
			j++;
		if (environ[i][j] == '=' && (j == (int)name_length || !overwrite))
			return (EXIT_SUCCESS);
		i++;
		j = 0;
	}
	if (!entry)
		return (-1);
	while (*name)
		*p++ = *name++;
	*p++ = '=';
	while (*value)
		*p++ = *value++;
	*p = '\0';
	if (!new_environ)
	{
		free(entry);
		return (-1);
	}
	_memcpy(new_environ, environ, i * sizeof(char *));
	new_environ[i] = entry;
	new_environ[i + 1] = NULL;
	environ = new_environ;
	return (EXIT_SUCCESS);
}
