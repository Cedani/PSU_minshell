/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_putstr.c
*/

#include "../../include/my_printf.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
