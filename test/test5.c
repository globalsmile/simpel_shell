#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

char *get_command_path(const char *command, char *command_path) {
    char *path = getenv("PATH");
    char *dir = path;
    size_t command_length = strlen(command);
    size_t dir_length;

    if (path == NULL)
        return NULL;

    while (*dir != '\0') {
        char *end = strchr(dir, ':');
        if (end == NULL)
            end = dir + strlen(dir);

        dir_length = end - dir;

        if (dir_length + command_length + 2 <= MAX_INPUT_LENGTH) {
            memcpy(command_path, dir, dir_length);
            command_path[dir_length] = '/';
            memcpy(command_path + dir_length + 1, command, command_length + 1);

            if (access(command_path, X_OK) == 0)
                return command_path;
        }

        if (*end == ':')
            dir = end + 1;
        else
            dir = end;
    }

    return NULL;
}

int main(void) {
    char *user_input = NULL;
    char *args[MAX_ARGS + 2];
    size_t length = 0;
    ssize_t read_user_input;
    int exit_shell = 0;
    pid_t child_pid;
    char *token;
    int arg_count = 0;

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
            char command_path[MAX_INPUT_LENGTH];

            if (get_command_path(args[0], command_path) != NULL) {
                execve(command_path, args, environ);
            }

            fprintf(stderr, "%s: command not found\n", args[0]);
        } else {
            int status;

            waitpid(child_pid, &status, 0);
            printf("child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
    }

    return EXIT_SUCCESS;
}

