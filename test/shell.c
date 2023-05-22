#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#include "/root/alx-low_level_programming/0x06-pointers_arrays_strings/3-strcmp.c"
/**
 * main - entry point
 *
 *Return: always 0
 */
int main(void)
{
	char *user_input = NULL;
	char **args = NULL;
	size_t length;
	ssize_t read_user_input;
	int exit_shell = 0;
	pid_t child_pid;
	int i;

	while (!exit_shell)
	{
		length = 0;
		printf("#cisfun$ ");
		fflush(stdout);

		read_user_input = _getline(&user_input, &length, stdin);
		if (read_user_input == -1)
			break;
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			int argc = 1;
			char *cmd = strtok(user_input, " \t\n");
			char *token = strtok(user_input, " \t\n");
			

			while (token != NULL)
			{
				args = realloc(args, (argc + 1) * sizeof(char *));
				if (args == NULL)
				{
					perror("memory allocation failed");
					exit(EXIT_FAILURE);
				}
				args[argc] = _strdup(token);
				if (args[argc] == NULL)
				{
					perror("memory allocation failed");
					exit(EXIT_FAILURE);
				}
				argc++;
				token = strtok(NULL, " \t\n");
			}
			args[0] = cmd;
			args[argc] = NULL;
			execve(args[0], args, environ);
			perror("execution failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			waitpid(child_pid, &status, 0);
			printf("child process %d exited with status %d\n", child_pid,WEXITSTATUS(status));
		}
		for (i  = 0; args != NULL && args[i] != NULL; i++)
			free(args[i]);
	}
	free(user_input);
	free(args);

        return (EXIT_SUCCESS);
}
