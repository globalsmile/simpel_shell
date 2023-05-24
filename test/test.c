#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_LENGTH 100

int main(void) {
    char *user_input = NULL;
    char **args = NULL;
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
            args = malloc(sizeof(char *) * 2);
            if (args == NULL) {
                perror("memory allocation failed");
                exit(EXIT_FAILURE);
            }
            args[0] = strdup(user_input);
            if (args[0] == NULL) {
                perror("memory allocation failed");
                exit(EXIT_FAILURE);
            }
            args[1] = NULL;
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

        free(args);
    }

    free(user_input);

    return EXIT_SUCCESS;
}

