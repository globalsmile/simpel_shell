#include <stdio.h>
#define UNUSED(x) int(x)

/*
 * main - entry point
 * @argc: count of arguments
 * @argv: pointer to a pointer of an array of chars
 * Return: always 0
 */
int main(int ac, char **av)
{
	int i;
	
	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);

	return (0);
}
