#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _path_linked_list - linked list of PATH directories
 * Return:  linked list of directories
 */
node_t *_path_linked_list(void)
{
	node_t *head_node = NULL;
	node_t *current_node = NULL;
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *token = strtok(path_copy, ":");

	if (path == NULL)
		return (NULL);
	if (path_copy == NULL)
		return (NULL);
	while (token != NULL)
	{
		node_t *new_node = (node_t *) malloc(sizeof(node_t));

		if (new_node == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		new_node->folder = _strdup(token);
		new_node->next = NULL;
		if (head_node == NULL)
		{
			head_node = new_node;
			current_node = new_node;
		}
		else
		{
			current_node->next = new_node;
			current_node = current_node->next;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (head_node);
}
