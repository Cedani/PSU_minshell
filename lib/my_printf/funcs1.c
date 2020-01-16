/*
** EPITECH PROJECT, 2019
** funcs1.c
** File description:
** print functions
*/

#include <stdarg.h>
#include "../../include/my_printf.h"

void prt_string(va_list ap)
{
    char *str = va_arg(ap, char *);
    my_putstr(str);
}

void prt_char(va_list ap)
{
    int i = va_arg(ap, int);
    my_putchar(i);
}

void prt_int(va_list ap)
{
    int i = va_arg(ap, int);
    my_put_nbr(i);
}

void prt_uns_int(va_list ap)
{
    int i = va_arg(ap, int);
    if (i < 0)
        i *= -1;
    my_put_nbr(i);
}

void prt_octal(va_list ap)
{
    char *result;
    int i = va_arg(ap, int);

    result = calc_base(i, "01234567");
    my_putstr(result);
}