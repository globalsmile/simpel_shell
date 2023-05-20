#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "/root/alx-low_level_programming/0x05-pointers_arrays_strings/9-strcpy.c"
/**
 * _strdup - duplicates a string
 * @user_input: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *user_input)
{
	size_t length = _strlen(user_input);
	char *dub = malloc((length + 1) * sizeof(char));

	if (!user_input)
		return (NULL);
	if (dub)
		_strcpy(dub, user_input);
	return (dub);
}
