#include "main.h"
#include <stdio.h>
int main(void)
{
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("Value of PATH: %s\n", path);
    } else {
        printf("PATH environment variable not found\n");
    }

    return 0;
}
