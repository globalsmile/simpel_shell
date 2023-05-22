#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
extern char **environ;
/**
 * _getline - collects a line input
 *
 * @line_to_get: specifies a buffer
 * @size: length of chars in the buffer
 * @source: specifies a file stream
 *
 * Return: int value
 */
ssize_t _getline(char **line_to_get, size_t *size, FILE *source);
/**
 *_split_string - splits strings into individual words
 * @user_input: collects user input
 * @total: counter
 * Return: an array of the splited strings
 */
char **_split_string(char *user_input, int *total);
/**
 * _strnup - allocate memory to copy string
 * @read_input: input string
 * @len: length of returning string
 * Return: new string
 */
char *_strnup(char *read_input, size_t len);
/**
 * __strlen - gets character string
 *
 * @s: character to getstring
 * Return: returns length
 */
int __strlen(const char *s);
/**
 * _strdup - duplicates a string
 * @user_input: string to duplicate
 * Return: duplicated string
 */
char *_strdup(char *user_input);
/**
 * _isspace - removes whitespce characters
 * @character: whitespace characters
 * Return: characters without whitespace
 */
int _isspace(int character);
/**
 * __split__string - splits a string
 * @user_input: string to split
 * @total: number of words in string
 * Return: splitted words
 */
char **__split__string(char *user_input, int *total);
/**
 * _getenv - gets an environment variable
 * @name: environment variable
 * Return: pointer to the environment variable
 */
char *_getenv(const char *name);
/**
 * _print_path_directories - prints directories in the PATH variable
 */
void _print_path_directories(void);
/**
 * struct node_s - singly linked list
 * @folder: linked list of directories
 * @next: points to the next node
 *
 * Description: singly linked list of directories
 */
typedef struct node_s
{
	char *folder;
	struct node_s *next;
} node_t;
/**
 * _path_linked_list - linked list of PATH directories
 * Return:  linked list of directories
 */
node_t *_path_linked_list(void);
/**
 * _setenv - changes or adds an env variable
 * @name: name of env variable
 * @value: value of env variable
 * @overwrite: overwrite env variable
 * Return: always 0
 */
int _setenv(const char *name, const char *value, int overwrite);
/**
 * _memcpy - copies from source to dest values in array
 * @dest: destination to copy to
 * @src: source to copy from
 * @n: n amount of times
 * Return: return the string value
 */
char *_memcpy(char **dest, char **src, unsigned int n);
/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name of the env variable
 * Return: Always 0
 */
int _unsetenv(const char *name);
/**
 * _strchr - locates character in string
 * @s: string to locate char
 * @c: character to find
 * Return: character value
 */
const char *_strchr(const char *s, char c);
#endif
