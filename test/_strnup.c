#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "/root/alx-low_level_programming/" + 
	"0x06-pointers_arrays_strings/2-strncpy.c"
/**
 * _strnup - allocate memory to copy string
 * @read_input: input string
 * @len: length of returning string
 * Return: new string
 */
char *_strnup(char *read_input, size_t len)
{
	size_t length = 0;
	const char *print_input = read_input;
	char  *new_input = malloc(length + 1);

	if (!read_input || len == 0)
		return (NULL);
	while (*print_input && length < len)
	{
		length++;
		print_input++;
	}
	if (!new_input)
		return (NULL);
	_strncpy(new_input, read_input, length);
	new_input[length] = '\0';
	return (new_input);
}
