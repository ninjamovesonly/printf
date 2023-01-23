#include "main.h"

/**
 * _printf - acts like default c print variadic function
 * @format: char * - string
 * Return: integer representing count of char * - string
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_character},
		{"s", print_character_array_or_string},
		{"%", print_percentage_symbol},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", ptint_rot13},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_lowercase_hex},
		{"X", print_uppercase_hex},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_chars = parse_helper(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
