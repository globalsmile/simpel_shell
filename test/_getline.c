#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _getline - collects a line input
 * @line_to_get: specifies a buffer
 * @size: length of chars in the buffer
 * @source: specifies a file stream
 * Return: int value
 */
ssize_t _getline(char **line_to_get, size_t *size, FILE *source)
{
	char *buffer = *line_to_get;
	size_t buff_size = *size;
	char *new_buffer = malloc(buff_size);
	size_t new_size = buff_size * 2;
	char *new_buffer1 = realloc(buffer, new_size);
	int j;
	size_t k = 0;

	if (!line_to_get || !size || !source)
		return (-1);
	if (!buffer || !buff_size)
	{
		buff_size = 128;
		if (!new_buffer)
			return (-1);
		buffer = new_buffer;
		*line_to_get = buffer;
		*size = buff_size;
	}
	while ((j = fgetc(source)) != EOF)
	{
		if (k + 1 >= buff_size)
		{
			if (!new_buffer1)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer1;
			*line_to_get = buffer;
			*size = buff_size = new_size;
		}
		buffer[k++] = j;
		if (j == '\n')
			break;
	}
	buffer[k] = '\0';
	if (k == 0)
		return (-1);
	return (k);
}
