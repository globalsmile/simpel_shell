#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 *_split_string - splits strings into individual words
 * @user_input: collects user input
 * @total: counter
 * Return: an array of the splited strings
 */
char **_split_string(char *user_input, int *total)
{
	char *duplicate = _strdup(user_input);
	char **words = NULL;
	char *token = strtok(duplicate, " ");
	char **temp = realloc(words, (*total) * sizeof(char *));

	*total = 0;
	if (!user_input || !total)
		return (NULL);
	if (!duplicate)
		return (NULL);
	while (token)
	{
		(*total)++;
		if (!temp)
		{
			free(words);
			free(duplicate);
			return (NULL);
		}
		words = temp;
		words[(*total) - 1] = _strnup(token, _strlen(token));
		token = strtok(NULL, " ");
	}
	free(duplicate);
	return (words);
}
