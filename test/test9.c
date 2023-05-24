#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_ARGS 10

extern char **environ;

int main(void) {
    char *user_input = NULL;
    char *args[MAX_ARGS + 2];
    size_t length = 0;
    ssize_t read_user_input;
    int exit_shell = 0;
    pid_t child_pid;

    while (!exit_shell) {
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
        int command_found = 0;
        printf("#cisfun$ ");
        fflush(stdout);

        read_user_input = getline(&user_input, &length, stdin);
        if (read_user_input == -1)
            break;

        user_input[strcspn(user_input, "\n")] = '\0';
        if (strlen(user_input) == 0)
            continue;

        if (path == NULL) {
            perror("getenv");
            exit(EXIT_FAILURE);
        }

        if (path_copy == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }


        while (dir != NULL) {
            char command_path[100];
            snprintf(command_path, sizeof(command_path), "%s/%s", dir, user_input);

            if (access(command_path, X_OK) == 0) {
                command_found = 1;
                break;
            }

            dir = strtok(NULL, ":");
        }

        free(path_copy);

        if (!command_found) {
            fprintf(stderr, "./hsh: 1: %s: command not found\n", user_input);
            continue;
        }

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            char *token;
            int arg_count = 0;

            token = strtok(user_input, " ");
            while (token != NULL && arg_count < MAX_ARGS) {
                args[arg_count] = token;
                token = strtok(NULL, " ");
                arg_count++;
            }
            args[arg_count] = NULL;

            if (execve(args[0], args, environ) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
    }

    free(user_input);

    return EXIT_SUCCESS;
}

