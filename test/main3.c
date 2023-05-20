#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	const char *user_input = "Hello World!";
	size_t maximum_length = 5;
	char *output = _strnup(user_input, maximum_length);

	if (output)
	{
		printf("Original: %s\n", user_input);
		printf("Strnup: %s\n", output);
		free(output);
	}
	return (EXIT_SUCCESS);
}

