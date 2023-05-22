#include <stdio.h>
#include "main.h"

int main(void) {
    node_t *pathList = _path_linked_list();
    node_t *current = pathList;

    if (pathList == NULL) {
        printf("Failed to build path list.\n");
        return 1;
    }
    while (current != NULL) {
        printf("%s\n", current->folder);
        current = current->next;
    }

    while (pathList != NULL) {
        node_t *temp = pathList;
        pathList = pathList->next;
        free(temp->folder);
        free(temp);
    }

    return 0;
}
