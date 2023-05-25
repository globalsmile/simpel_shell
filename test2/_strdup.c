#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "_pointers.h"
/**
 * _strdup - duplicates a string
 * @user_input: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *user_input)
{
	size_t length = __strlen(user_input);
	char *dub = malloc((length + 1) * sizeof(char));

	if (!user_input)
		return (NULL);
	if (dub)
		_strcpy(dub, user_input);
	return (dub);
}
