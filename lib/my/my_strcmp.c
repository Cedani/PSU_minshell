/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_strcmp.c
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_strlen(s1);
    int j = my_strlen(s2);
    int let = 0;
    int ret = i - j;
    if (ret < 0) {
        ret = i;
    } else {
        ret = j;
    }
    while (let <= ret) {
        if (s1[let] != s2[let]) {
            ret = s1[let] - s2[let];
            return ret;
        } else {
            let++;
        }
    }
    return 0;
}