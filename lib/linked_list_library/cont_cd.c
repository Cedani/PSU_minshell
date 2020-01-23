/*
** EPITECH PROJECT, 2020
** continuation of cd's funcctions implementation
** File description:
** cont_cd.c
*/

#include "../../include/mini_one.h"

char *give_old(char *oldpwd, int todo)
{
    static char *old = NULL;

    if (todo == 1) {
        old = oldpwd;
        return NULL;
    } else
        return (old);
}

char *new_pwd(char *path, char *pwd)
{
    struct stat stat1;
    char *test = my_strcat(pwd, "/");

    test = my_strcat(test, path);
    if (stat(test, &stat1) == 0)
        path = test;
    return (path);
}

int cd_file(char *path, t_list *list)
{
    int size = 50;
    struct stat stat1;
    t_list *tmp = list;
    char *buffer = NULL;
    int ok = 0;

    stat(path, &stat1);
    if (!S_ISDIR(stat1.st_mode) && !S_ISLNK(stat1.st_mode)) {
        my_printf("%s: Not a directory.\n", path);
        return (0);
    }
    chdir(path);
    editing_pwd(&list, path);
}

int alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (0);
    if (c >= '0' && c <= '9')
        return (0);
    if (c >= 'A' && c <= 'Z')
        return (0);
    if (c == '_')
        return (0);
    return (1);
}