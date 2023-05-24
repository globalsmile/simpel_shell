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
    char **args = NULL;
    size_t length = 0;
    ssize_t read_user_input;
    int exit_shell = 0, i;
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

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            char *token;
            int arg_count = 0;

            token = strtok(user_input, " ");
            while (token != NULL && arg_count < MAX_ARGS) {
                arg_count++;
                token = strtok(NULL, " ");
            }

            args = malloc(sizeof(char *) * (arg_count + 1));
            if (args == NULL) {
                perror("memory allocation failed");
                exit(EXIT_FAILURE);
            }

            token = strtok(user_input, " ");
            i = 0;
            while (token != NULL) {
                args[i] = strdup(token);
                if (args[i] == NULL) {
                    perror("memory allocation failed");
                    exit(EXIT_FAILURE);
                }
                token = strtok(NULL, " ");
                i++;
            }
            args[arg_count] = NULL;

            if (execve(args[0], args, environ) == -1) {
                fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }

        if (args != NULL) {
            for (i = 0; args[i] != NULL; i++) {
                free(args[i]);
            }
            free(args);
        }
    }

    free(user_input);

    return EXIT_SUCCESS;
}

