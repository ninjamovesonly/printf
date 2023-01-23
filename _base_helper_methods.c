#include "main.h"
#include <stdio.h>

/**
 * print_binary - convert to binary
 * @list: arguments list
 * Return: integer
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_write_char_helper('0'));
	if (num < 1)
		return (-1);
	len = _base_length(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = _reverse_string(str);
	if (rev_str == NULL)
		return (-1);
	_print_character_array(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - prints in octal base
 * @list: arguments list
 * Return: integer
 */
int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_write_char_helper('0'));
	if (num < 1)
		return (-1);

	len = _base_length(num, 8);
	octal_rep = malloc(sizeof(char) * len + 1);

	if (octal_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;
	}

	octal_rep[len] = '\0';
	rev_str = _reverse_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	_print_character_array(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * print_lowercase_hex - prints base16 in lowercase
 * @list: arguments list
 * Return: integer
 */
int print_lowercase_hex(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_write_char_helper('0'));
	if (num < 1)
		return (-1);
	len = _base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_checker(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = _reverse_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	_print_character_array(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * print_uppercase_hex - prints base16 in uppercase
 * @list: arguments list
 * Return: integer
 */
int print_uppercase_hex(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_write_char_helper('0'));
	if (num < 1)
		return (-1);
	len = _base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_checker(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = _reverse_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	_print_character_array(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * hex_checker - checks hex method
 * @num: integer
 * @x: character
 * Return: integer
 */
int hex_checker(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
