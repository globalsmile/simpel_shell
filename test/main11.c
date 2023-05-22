#include <stdio.h>
#include "main.h"
int main() {
    char **env = environ;

    printf("Original Environment:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    printf("Deleting environment variable:\n");
    _unsetenv("MY_VAR");

    printf("Modified Environment:\n");
    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    printf("Deleting non-existing environment variable:\n");
    _unsetenv("NON_EXISTING_VAR");

    printf("Modified Environment:\n");
    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    return 0;
}
