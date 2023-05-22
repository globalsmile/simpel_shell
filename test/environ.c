#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(void)
{

	for (char **env = environ; *env != NULL; env++)
		printf("%s\n",*env);
	return (EXIT_SUCCESS);
}
