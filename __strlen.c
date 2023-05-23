#include "main.h"
/**
 * __strlen - gets character string
 *
 * @s: character to getstring
 * Return: returns length
 */
int __strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{}
	return (i);
}
