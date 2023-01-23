#include "main.h"

/**
 * print_number - print number
 * @args: arguments list
 * Return: integer
 */
int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _write_char_helper('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char_helper('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_unsigned_number - print positive integer
 * @n: positive integer
 * Return: integer
 */
int print_unsigned_number(unsigned int n)
{
	int div, len;
	unsigned int num;

	div = 1;
	len = 0; 

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char_helper('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
