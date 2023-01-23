#include "main.h"

/**
 * _write_char_helper - alias of default write method
 * @c: character
 * Return: integer
 */

int _write_char_helper(char c)
{
	return (write(1, &c, 1));
}
