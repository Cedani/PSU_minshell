/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat (char *dest , char const *src)
{
    int len = my_strlen(dest) + my_strlen(src) + 1;
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * len);

    while (j < len) {
        if (dest[i]){
            str[j] = dest[i];
            i += 1;
        } else {
            str[j] = src[k];
            k += 1;
        }
        j += 1;
    }
    return (str);
}