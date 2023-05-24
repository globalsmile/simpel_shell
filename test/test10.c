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
                args[arg_count] = token;
                token = strtok(NULL, " ");
                arg_count++;
            }
            args[arg_count] = NULL;

            if (execve(args[0], args, environ) == -1) {
                write(STDERR_FILENO, "./hsh", strlen("./hsh"));
                write(STDERR_FILENO, ": 1: ", 5);
                write(STDERR_FILENO, args[0], strlen(args[0]));
                write(STDERR_FILENO, ": not found\n", 17);
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

