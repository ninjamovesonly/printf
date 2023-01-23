#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a key value pair for symbols and functions
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/* main methods */
int _printf(const char *format, ...);
int _write_char_helper(char);
int print_character(va_list);
int print_character_array_or_string(va_list);
int print_percentage_symbol(va_list);
int print_integer(va_list);
int print_unsigned_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int ptint_rot13(va_list);
int print_octal(va_list list);
int print_lowercase_hex(va_list list);
int print_uppercase_hex(va_list list);
int hex_checker(int, char);
int parse_helper(const char *format, conver_t f_list[], va_list arg_list);

/* helper methods */
unsigned int _base_length(unsigned int, int);
char *_reverse_string(char *);
void _print_character_array(char *str);
char *_memory_copy(char *dest, char *src, unsigned int n);
int print_unsigned_number(unsigned int);

#endif
