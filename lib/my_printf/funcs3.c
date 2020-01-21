/*
** EPITECH PROJECT, 2019
** funcs3.c
** File description:
** useful function
*/

#include <stdarg.h>
#include "../../include/my_printf.h"

int count_space(char *str, int *i)
{
    int j = 0;

    while (str[*i] == ' ') {
        *i++;
        j++;
    }
    return (j);
}

int count_digit(int nb)
{
    int i = 0;
    while (nb > 0) {
        i += 1;
        nb /= 10;
    }
    return (i);
}

int print_zero(int nb_zer, char s, va_list ap)
{
    if (s == 'd') {
        int i = va_arg(ap, int);
        int k = count_digit(i);
        nb_zer -= k;
        while (nb_zer > 0) {
            my_putchar('0');
            nb_zer -= 1;
        }
        my_put_nbr(i);
        return (-1);
    }
    return (-2);
}