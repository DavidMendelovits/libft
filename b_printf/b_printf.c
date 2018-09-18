#include "b_printf.h"

void            putnbr_base(unsigned long nbr, int base, int *chars)
{
    if (nbr >= (unsigned long)base)
    {
        putnbr_base(nbr / base, base, chars);
    }
    if (nbr > (unsigned long)base && nbr % base > 10)
    {
        ft_putchar(NUM[nbr % base]);
        *chars += 1;
    }
    else
    {
        ft_putchar(NUM[nbr % base]);
        *chars += 1;
    }
}

int             parse(const char *format, va_list arg_list)
{
    int         i;
    char        specifier;
    int         printed_chars;

    i = 0;
    printed_chars = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            specifier = spec_check(format, &i);
            if (specifier)
            {
                printed_chars += dispatch(arg_list, specifier);
            }
            else
            {
                write(2, "error\n", 6);
            }
        }
        else
        {
            write(1, &format[i], 1);
            i += 1;
            printed_chars += 1;
        }
    }
    return (printed_chars);
}

int             b_printf(const char *format, ...)
{
    int             printed_chars;
    va_list         arg_list;

    va_start(arg_list, format);
    printed_chars = parse(format, arg_list);
    return (printed_chars);
}