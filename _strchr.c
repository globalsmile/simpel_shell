#include "main.h"
/**
 * _strchr - Identify character in string
 * @s: string to locate char
 * @c: character to find
 * Return: character value
 */
const char *_strchr(const char *s, char c)
{
	int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] == c)
		{
			return (s + j);
		}
	}
	if (s[j] == c)
		return (s + j);
	return (0);
}
