#include "main.h"

/**
 * print_character - print character
 * @list: arguments list
 * Return: integer
 */
int print_character(va_list list)
{
	_write_char_helper(va_arg(list, int));
	return (1);
}

/**
 * print_character_array_or_string - print char * - string
 * @list: arguments list
 * Return: integer
 */
int print_character_array_or_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char_helper(str[i]);
	return (i);
}

/**
 * print_percentage_symbol - print percentage symbol
 * @list: arguments list
 * Return: integer
 */
int print_percentage_symbol(__attribute__((unused))va_list list)
{
	_write_char_helper('%');
	return (1);
}

/**
 * print_integer - print integer
 * @list: arguments list
 * Return: integer
 */
int print_integer(va_list list)
{
	int num_length;

	num_length = print_number(list);
	return (num_length);
}

/**
 * print_unsigned_integer - print only positive integer
 * @list: arguments list
 * Return: integer
 */
int print_unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsigned_number(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_number(num));
}
