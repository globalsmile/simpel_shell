#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

int main(void) {
    char *user_input = NULL;
    char *args[MAX_ARGS + 2];
    size_t length = 0;
    ssize_t read_user_input;
    int exit_shell = 0;
    char *token;
    int arg_count = 0;
    pid_t child_pid;

    while (!exit_shell) {
        printf("#cisfun$ ");
        fflush(stdout);

        read_user_input = getline(&user_input, &length, stdin);
        if (read_user_input == -1)
            break;

        user_input[strcspn(user_input, "\n")] = '\0';
        if (strlen(user_input) == 0)
            continue;

        token = strtok(user_input, " ");
        while (token != NULL && arg_count < MAX_ARGS) {
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
            char *path = getenv("PATH");

            if (path != NULL) {
                char *dir = strtok(path, ":");

                while (dir != NULL) {
                    size_t dir_length = strlen(dir);
                    size_t command_length = strlen(args[0]);
		    char command_path[MAX_INPUT_LENGTH];
                    
		    if (dir_length + command_length + 2 > MAX_INPUT_LENGTH) {
                        fprintf(stderr, "Command path too long\n");
                        exit(EXIT_FAILURE);
                    }

                    strncpy(command_path, dir, MAX_INPUT_LENGTH);
                    command_path[dir_length] = '/';
                    strncpy(command_path + dir_length + 1, args[0], MAX_INPUT_LENGTH - dir_length - 1);

                    if (access(command_path, X_OK) == 0) {
                        execve(command_path, args, environ);
                        perror("execve failed");
                        exit(EXIT_FAILURE);
                    }

                    dir = strtok(NULL, ":");
                }
            }

            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
    }

    free(user_input);

    return EXIT_SUCCESS;
}

