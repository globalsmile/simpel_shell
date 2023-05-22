#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void) {
    char **env = environ;

    printf("Original Environment:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    printf("Setting environment variable:\n");
    _setenv("MY_VAR", "Hello, World!", 1);

    printf("Modified Environment:\n");
    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    printf("Overwriting environment variable:\n");
    _setenv("PATH", "/usr/local/bin", 1);
    printf("Modified Environment:\n");
    
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    printf("Adding environment variable without overwriting:\n");
    _setenv("MY_VAR", "New Value", 0);

    printf("Modified Environment:\n");
    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    printf("\n");

    return 0;
}

