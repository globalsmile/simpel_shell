#include "_pointers.h"
/**
 * _strcpy - main function to copy
 *
 * @dest: destination to copy
 * @src: src
 *
 * Return: a character value
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= __strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
