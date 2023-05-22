#include <stddef.h>
#include "main.h"
/**
 * _getenv - gets an environment variable
 * @name: environment variable
 * Return: pointer to the environment variable
 */
char *_getenv(const char *name)
{
	size_t len = 0;
	const char *first_entry;
	size_t j = 0;
	int i;

	if (name == NULL || environ == NULL)
		return (NULL);
	while (name[len] != '\0')
		len++;
	for (i = 0; environ[i] != NULL; i++)
	{
		first_entry = environ[i];
		while (first_entry[j] == name[j] && name[j] != '\0')
			j++;
		if (j == len && first_entry[j] == '=')
			return ((char *)&first_entry[j + 1]);
	}
	return (NULL);
}
