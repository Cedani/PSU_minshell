/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_strlen.c
*/

#include "../../include/my_printf.h"

void my_prt_nb_char(va_list ap)
{
    char *str = va_arg(ap, char *);
    int i = 0;

    while (str[i] != '%')
        i++;
    my_put_nbr(i);
}

void prt_mod(va_list ap)
{
    my_putchar('%');
}