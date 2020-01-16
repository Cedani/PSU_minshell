/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** put a char
*/

#include "../../include/my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
