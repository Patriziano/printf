#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
*_printf - function that produces output according to a format
*@format: a character string
*
*Return: Always 0
*/
int _printf(const char *format, ...)
{
	int count;
	int c;
	char *s;

	count = 0;

	va_list(ap);
	va_start(ap, format);

	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		}
		if (*format == c)
		{
			c = va_arg(ap, int);
			putchar(c);
			count++;
		}
		if (*format == 's')
		{
			s = va_arg(ap, char*);
			while (*s != '\0')
			{
				putchar(*s);
				s++;
				count++;
			}
		}
		else if (*format == '%')
		{
			putchar('%');
			count++;
		}
	else 
	{
		putchar(*format);
		count++;
	}
	format++;

		
	}
	va_end(ap);
	return(count);
}
