/*
** EPITECH PROJECT, 2019
** funcs2.c
** File description:
** rest of printing functions
*/

#include <stdarg.h>
#include "../../include/my_printf.h"

void prt_hexadecimal_min(va_list ap)
{
    char *result;
    int i = va_arg(ap, int);

    result = calc_base(i, "0123456789abcdef");
    my_putstr(result);
}

void prt_hexadecimal_maj(va_list ap)
{
    char *result;
    int i = va_arg(ap, int);

    result = calc_base(i, "0123456789ABCDEF");
    my_putstr(result);
}

void prt_uns_bin(va_list ap)
{
    char *result;
    int i = va_arg(ap, int);

    result = calc_base(i, "01");
    my_putstr(result);
}

void prt_flag_point(va_list ap)
{
    char *result;
    long long i = va_arg(ap, long long);

    result = put_nbr_base(i, "0123456789abcdef");
    my_putstr("0x");
    my_putstr(result);
}

void prt_flag_s(va_list ap)
{
    char *result;
    char *str = va_arg(ap, char *);

    while (*str) {
        if (*str < 32 || *str >= 127) {
            result = calc_base(*str, "01234567");
            my_putchar('\\');
            my_putstr("00");
            my_putstr(result);
        } else
            my_putchar(*str);
        str++;
    }
}