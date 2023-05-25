#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "_pointers.h"

/**
 * __split__string - splits a string
 * @user_input: string to split
 * @total: number of words in string
 * Return: splitted words
 */
char **__split__string(char *user_input, int *total)
{
	char **sentence = NULL;
	int len = __strlen(user_input);
	int word_count = 0;
	int i = 0;

	if (!user_input || !total)
		return (NULL);
	if (len == 0)
		return (NULL);
	while (i < len)
	{
		int word_start = i;

		while (i < len && _isspace(user_input[i]))
			i++;
		while (i < len && !_isspace(user_input[i]))
			i++;
		if (word_start < i)
		{
			char **temp = realloc(sentence, (word_count + 1) * sizeof(char *));
			int word_length = i - word_start;

			if (!temp)
				return (NULL);
			sentence = temp;
			sentence[word_count] = malloc((word_length + 1) * sizeof(char));
			if (!sentence[word_count])
				return (NULL);
			_strncpy(sentence[word_count], user_input + word_start, word_length);
			sentence[word_count][word_length] = '\0';
			word_count++;
		}
	}
	*total = word_count;
	return (sentence);
}
