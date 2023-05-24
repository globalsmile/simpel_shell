#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _getline - reads a line of input from stdin
 * Return: pointer to the line read, or NULL on failure or end of file
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos = 0;
	static int len = 0;

	char *line = NULL;
	int c;

	while (1) {
		/* if buffer is empty, read more data */
		if (pos >= len) {
			len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (len <= 0)
				return NULL;
			pos = 0;
		}

		/* scan buffer for newline character */
		for (; pos < len; pos++) {
			c = buffer[pos];
			if (c == '\n') {
				line = malloc(pos + 1);
				if (line == NULL)
					return NULL;
				memcpy(line, buffer, pos);
				line[pos] = '\0';
				pos++;
				memmove(buffer, buffer + pos, len - pos);
				len -= pos;
				pos = 0;
				return line;
			}
		}

		/* if no newline character found, move remaining data to beginning of */
		if (len >= BUFFER_SIZE) {
			pos = 0;
			len = 0;
			return NULL;
		}
		memmove(buffer, buffer + pos, len - pos);
		len -= pos;
		pos = 0;
	}
}
