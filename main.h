#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * _getline - collects a line input
 *
 * @line_to_get: specifies a buffer
 * @size: length of character the buffer
 * @source: specifies a file stream
 *
 * Return: int value
 */
ssize_t _getline(char **line_to_get, size_t *size, FILE *source);
/**
 *_split_string - splits strings into individual wordings
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
 * _strlen - gets character string
 *
 * @s: character to getstring
 * Return: returns length
 */
int _strlen(char *s);
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
#endif
