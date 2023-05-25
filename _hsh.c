#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#include "/root/printf/_printf.c"
#include "/root/alx-low_level_programming/0x06-pointers_arrays_strings/3-strcmp.c"

/**
 * main - entry point
 * Return: always 0
 */
int main(void)
{
	char *user_input = NULL;
	char *args[MAX_ARGS + 2];
	size_t length = 0;
	ssize_t read_user_input;
	int exit_shell = 0;
	pid_t child_pid;

	while (!exit_shell)
	{
		char *token;
		int arg_count = 0;

		_printf("#cisfun$ ");
		fflush(stdout);

		read_user_input = _getline(&user_input, &length, stdin);
		if (read_user_input == -1)
			break;
		user_input[_strcspn(user_input, "\n")] = '\0';
		if (__strlen(user_input) == 0)
			continue;
		if (_strcmp(user_input, "exit") == 0)
		{
			exit_shell = 1;
			continue;
		}
		token = strtok(user_input, " ");
		while (token != NULL && arg_count < MAX_ARGS)
		{
			args[arg_count] = _strdup(token);
			token = strtok(NULL, " ");
			arg_count++;
		}
		args[arg_count] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			char command_path[MAX_INPUT_LENGTH];

			if (_cmd_path(args[0], command_path) != NULL)
			{
				execve(command_path, args, environ);
				write(STDERR_FILENO, "./hsh", __strlen("./hsh"));
				write(STDERR_FILENO, ": 1: ", 5);
				write(STDERR_FILENO, args[0], __strlen(args[0]));
				write(STDERR_FILENO, ": not found\n", 17);
				exit(EXIT_FAILURE);
			}
			if (execve(args[0], args, environ) == -1)
			{
				write(STDERR_FILENO, "./hsh", __strlen("./hsh"));
				write(STDERR_FILENO, ": 1: ", 5);
				write(STDERR_FILENO, args[0], __strlen(args[0]));
				write(STDERR_FILENO, ": not found\n", 17);
				exit(EXIT_FAILURE);
			}
			write(STDERR_FILENO, "./hsh", __strlen("./hsh"));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, args[0], __strlen(args[0]));
			write(STDERR_FILENO, ": not found\n", 17);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(child_pid, &status, 0);
			_printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
		}
	}
	return (EXIT_SUCCESS);
}

