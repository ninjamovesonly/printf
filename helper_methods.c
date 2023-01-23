#include "main.h"
#include <stdio.h>

/**
 * _reverse_string - reverse char * - string
 * @s: char * - string
 * Return: char * - string
 */
char *_reverse_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memory_copy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * _print_character_array - print characters using alias _write_char_helper method 
 * @str: char * - string
 * Return: nothing
 */
void _print_character_array(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_write_char_helper(str[i]);
}

/**
 * _base_length - print length
 * @num: positive integer
 * @base: integer
 * Return: positive integer
 */
unsigned int _base_length(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * _memory_copy - copy memory
 * @dest: char * - string
 * @src: char * - string
 * @n: positive integer
 * Return: char * - string
 */
char *_memory_copy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
