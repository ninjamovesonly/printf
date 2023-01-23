#include "main.h"

/**
 * print_reversed - reverse and print char * - string
 * @arg: arguments list
 * Return: integer
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_write_char(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * convert_to_rot13 - print rot13
 * @list: arguments list
 * Return: converted string
 */
int ptint_rot13(va_list list)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_write_char(u[x]);
				break;
			}
		}
		if (x == 53)
			_write_char(str[i]);
	}
	return (i);
}
