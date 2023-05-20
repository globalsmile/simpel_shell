#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - entry point
 *
 *Return: always 0
 */
int main(void)
{
        char *user_input = NULL;
        size_t length;
        ssize_t read_user_input;

        length = 0;
        printf("$ ");
        fflush(stdout);

        read_user_input = _getline(&user_input, &length, stdin);
        if (read_user_input != -1)
                printf("%s", user_input);

        free(user_input);

        return (EXIT_SUCCESS);
}
