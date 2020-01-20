/*
** EPITECH PROJECT, 2020
** continuation of cd's funcctions implementation
** File description:
** cont_cd.c
*/

#include "../../include/mini_one.h"

char *good_link(char *path, char *buffer)
{
    struct stat stat1;
    int size = 50;
    int ok = 0;

    buffer = malloc(sizeof(char) * size +1);
    if (S_ISLNK(stat1.st_mode)) {
        readlink(path, buffer, size);
        ok = stat(buffer, &stat1);
        while (ok != 0) {
            size += 10;
            buffer = malloc(sizeof(char) * size +1);
            readlink(path, buffer, size);
            ok = stat(buffer, &stat1);
        }
    }
    return (buffer);
}

char *new_pwd(char *path, char *pwd) {
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
        my_printf("no such file or directory\n");
        return (0);
    }
    if (S_ISLNK(stat1.st_mode))
        path = good_link(path, buffer);
    chdir(path);
    editing_pwd(&list, path);
}