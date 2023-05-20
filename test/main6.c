#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * main - entry point
 * Return: exit success
 */
int main(void)
{
        char *user_input = "Write a function that splits a string"
                " and returns an array of the words"
                " in the string";
        int total;
        char **sentence = __split__string(user_input, &total);
        int i;

        if (sentence)
        {
                printf("Number of words: %d\n", total);
                for (i = 0; i < total; i++)
                {
                        printf("Word %d: %.*s\n", i + 1, (int)_strlen(sentence[i]), sentence[i]);
                        free(sentence[i]);
                }
                free(sentence);
        }

        return (EXIT_SUCCESS);
}
