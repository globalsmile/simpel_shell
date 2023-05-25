#include "main.h"
/**
 * _strcspn - length of prefix substring
 * @s: string to go through
 * @reject: accepted bytes
 * Return: returns usigned values
 */
size_t _strcspn(const char *s, const char *reject)
{
	const char *p = s;
	size_t total = 0;

	while (*p)
	{
		const char *q = reject;

		while (*q)
		{
			if (*p == *q)
				return (total);
			q++;
		}
		p++;
		total++;
	}

	return (total);
}

