/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** must print string and parameters
*/

#include "../../include/my_printf.h"

static func_list_t func_list_1[] = {
    {'c', prt_char},
    {'i', prt_int},
    {'s', prt_string},
    {'d', prt_int},
    {'u', prt_uns_int},
    {'o', prt_octal},
    {'x', prt_hexadecimal_min},
    {'X', prt_hexadecimal_maj},
    {'b', prt_uns_bin},
    {'S', prt_flag_s},
    {'p', prt_flag_point},
    {'%', prt_mod}
};

int for_spe(va_list ap, char s)
{
    int ret = 0;
    for (int i = 0; i < 13; i += 1) {
        if (func_list_1[i].c == s) {
            func_list_1[i].fun(ap);
            ret = 1;
        }
    }
    return (ret);
}

void my_printf(char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    while (*s != '\0') {
        if (*s == '%') {
            if (for_spe(ap, s[1]) == 1)
                s += 2;
            else {
                my_putchar(*s);
                s += 1;
            }
        }
        else if (*s != '\0') {
            my_putchar(*s);
            s += 1;
        }
    }
    va_end(ap);
}