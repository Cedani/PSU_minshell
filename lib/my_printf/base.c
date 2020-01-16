/*
** EPITECH PROJECT, 2019
** base
** File description:
** convert into given base
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my_printf.h"

char *calc_base(int nb, char const *base)
{
    int i = 0;
    int k = 0;
    char *result = malloc(sizeof(result));
    if (nb < 0)
        nb *= -1;
    while (nb > 0) {
        i = nb % my_strlen(base);
        result[k] = base[i];
        k++;
        nb /= my_strlen(base);
    }
    result = my_revstr(result);
    return (result);
}

char *put_nbr_base(long long nb, char const *base)
{
    int i = 0;
    int k = 0;
    char *result = malloc(sizeof(result));
    if (nb < 0)
        nb *= -1;
    while (nb > 0) {
        i = nb % my_strlen(base);
        result[k] = base[i];
        k++;
        nb /= my_strlen(base);
    }
    result = my_revstr(result);
    return (result);
}
