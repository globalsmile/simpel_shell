#include <stdio.h>
#include "main.h"
/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	char ch = ' ';

	if (_isspace(ch))
		printf("'%c' is a whitespace character.\n", ch);
	else
		printf("'%c' is not a whitespace character.\n", ch);
	return (EXIT_SUCCESS);
}
