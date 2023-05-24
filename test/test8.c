#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#define MAX_ARGS 10

char *get_command_path(const char *command) {
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    char *command_path = NULL;

    while (dir != NULL) {
        command_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(command_path, "%s/%s", dir, command);

        if (access(command_path, X_OK) == 0) {
            return command_path;
        }

        free(command_path);
        command_path = NULL;

        dir = strtok(NULL, ":");
    }

    return NULL;
}

int main(void) {
    char *user_input = NULL;
    char **args = NULL;
    size_t length = 0;
    ssize_t read_user_input;
    int exit_shell = 0;
    pid_t child_pid;

    while (!exit_shell) {
	char *token;
        int arg_count = 1;
	char *command_path = get_command_path(user_input);
        printf("#cisfun$ ");
        fflush(stdout);

        read_user_input = getline(&user_input, &length, stdin);
        if (read_user_input == -1)
            break;

        user_input[strcspn(user_input, "\n")] = '\0';
        if (strlen(user_input) == 0)
            continue;

        if (command_path == NULL) {
            fprintf(stderr, "%s: command not found\n", user_input);
            continue;
        }

        args = malloc(sizeof(char *) * (MAX_ARGS + 2));
        args[0] = command_path;

        token = strtok(user_input, " ");
        while (token != NULL && arg_count < MAX_ARGS + 1) {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }
        args[arg_count] = NULL;

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            execve(args[0], args, environ);
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }

        free(command_path);
        free(args);
    }

    free(user_input);

    return EXIT_SUCCESS;
}

