#include <stdio.h>
#include "main.h"
/**
 * main - entry point
 * Return: Always zero
 */
int main(void)
{
	char *source_input = "Hello, World";
	char *dub = _strdup(source_input);

	if (dub)
	{
		printf("source string: %s\n", source_input);
		printf("duplicate string: %s\n", dub);
		free(dub);
	}
	else
		printf("memory allocation failed.\n");
	return (EXIT_SUCCESS);
}
