#include "main.h"
/**
 * _isspace - removes whitespce characters
 * @character: whitespace characters
 * Return: characters without whitespace
 */
int _isspace(int character)
{
	return (character == ' ' || character == '\t' || character == '\n'
			|| character == '\v' || character == '\f' ||
			character == '\r');
}
