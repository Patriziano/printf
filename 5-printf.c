#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_custom(const char* format, ...)
{       
        va_list cosp;
        va_start(cosp, format);
        
        while (*format != '\0')
        {       
                if (*format == '%')
                {       
                         switch (*(++format))
                         {       
                                 case 'S':
                                {       
                                         const char* po = va_arg(cosp, const char*); 
                                                 
                                         while (*po != '\0')
                                         {       
                                                 if (*po < 32 || *po >= 127)
                                                 {       
                                                         printf("\\x%02X", *po);
                                                 }       
                                                 else
                                                 {       
                                                          putchar(*po);
                                                 }        
                                                 po++;

					 }
					 break;
				}
				 default:

				putchar('%');
				putchar(*format);

				break;

			 }
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(cosp);
}
/**
 * main - prints the string 'S'
 * @S: the string to be printed
 * Return: Always zero (0)
 */
int main(void)
{
	print_custom("%S\n", "Best\nSchool");
	return (0);
}
