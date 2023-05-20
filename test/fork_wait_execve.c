#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	char *cmd = "/bin/ls";
	char *args[] = {"ls", "-l", "/tmp", NULL};
	int child_process = 5;
	int i;

	for (i = 0; i < child_process; i++)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			printf("child process %d executing:\n", getpid());
			execve(cmd, (char * const *)args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(child_pid, &status, 0);
			printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
		}
	}
	return (EXIT_SUCCESS);
}
