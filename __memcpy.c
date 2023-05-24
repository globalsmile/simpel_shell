#include "main.h"
/**
 * __memcpy - copies from source to dest values in array
 * @dest: destination to copy to
 * @src: source to copy from
 * @n: n amount of times
 * Return: return the string value
 */
char *__memcpy(char *dest, const char *src, unsigned int n)
{
        unsigned int k;

        for (k = 0; k < n; k++)
        {
                dest[k] = src[k];
        }
        return (dest);
}
