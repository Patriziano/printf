#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - print the format specifiers "d" and "i"
 * @d: first format specifier
 * @i: second forma
 */

int _printf(const char *format, ...)
{
	int count;
	count = 0;
	va_list id;
	va_start(id, format);
	{
		while (*format != '\0')
		{
			int p;

			if (*format == 'd' || *format == 'i')
			{
				p = va_arg(id, int);
				printf("%d", p);
				count += snprintf(NULL, 0, "%d", p);
			}
			else 
			{
				putchar(*format);
				count++;
			}
			format++;
		}

	}
	va_end(id);
	return (count);
}
