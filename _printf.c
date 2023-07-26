#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int char_count = 0;

    va_start(ap, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            char_count++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(ap, int);
                    putchar(c);
                    char_count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(ap, char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        char_count++;
                        s++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(ap, int);
                    printf("%d", num);
                    char_count++;
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(ap, unsigned int);
                    printf("%u", num);
                    char_count++;
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(ap, unsigned int);
                    printf("%o", num);
                    char_count++;
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(ap, unsigned int);
                    printf("%x", num);
                    char_count++;
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(ap, unsigned int);
                    printf("%X", num);
                    char_count++;
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(ap, void *);
                    printf("%p", ptr);
                    char_count++;
                    break;
                }
                case '%':
                {
                    putchar('%');
                    char_count++;
                    break;
                }
                default:
                {
                    putchar('%');
                    putchar(*format);
                    char_count += 2;
                    break;
                }
            }
        }
        format++;
    }

    va_end(ap);
    return char_count;
}
