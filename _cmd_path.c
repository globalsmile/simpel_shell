#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * _cmd_path - gets the command path
 * cmd: command
 * cmd_path: command path
 * Returns: full command PATH
 */
char *_cmd_path(const char *cmd, char *cmd_path)
{
	char *path = _getenv("PATH");
	const char *dir = path;
	size_t cmd_length = __strlen(cmd);
	size_t dir_length;
	
	if (path == NULL)
		return (NULL);
	
	while (*dir != '\0')
	{
		const char *end = _strchr(dir, ':');

		if (end == NULL)
			end = dir + __strlen(dir);
		dir_length = end - dir;
		if (dir_length + cmd_length + 2 <= MAX_INPUT_LENGTH)
		{
			__memcpy(cmd_path, dir, dir_length);
			cmd_path[dir_length] = '/';
			__memcpy(cmd_path + dir_length + 1, cmd, cmd_length + 1);
			if (access(cmd_path, X_OK) == 0)
				return (cmd_path);
		}

		if (*end == ':')
			dir = end + 1;
		else
			dir = end;
	}

	return (NULL);
}
