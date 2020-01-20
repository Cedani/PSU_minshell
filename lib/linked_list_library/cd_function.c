/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "../../include/mini_one.h"

void my_memset(char *buffer, int size)
{
    for (int i = 0; i < size; i += 1)
        buffer[i] = '\0';
}

char *give_path(t_list *list)
{
    char *filepath = NULL;
    int last_s = 0;

    for (; my_strcmp(list->key, "PWD") != 0; list = list->next);
    for (int i = 0; list->path[i]; i += 1)
        if (list->path[i] == '/')
            last_s = i;
    filepath = malloc(sizeof(*filepath) * last_s);
    for (int i = 0; i < last_s; i += 1)
        filepath[i] = list->path[i];
    return (filepath);
}

void swap(char **s1, char *s2)
{
    s1[0] = s2;
}

void editing_pwd(t_list **list, char *path)
{
    t_list *tmp = (*list);
    char *old = NULL;

    tmp = (*list);
    for (; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->key, "PWD") == 0) {
            old = tmp->path;
            tmp->path = give_cwd();
        }
    tmp = (*list);
    for (; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->key, "OLDPWD") == 0)
            swap(&tmp->path, old);
}

void cd(char *command, t_list *list)
{
    t_list *tmp = list;
    int size = 0;
    char **arg = my_str_to_word_array(command, &size);
    char *path = NULL;

    if (size == 1) {
        for (; my_strcmp(tmp->key, "HOME") != 0; tmp = tmp->next);
        chdir(tmp->path);
        path = tmp->path;
        editing_pwd(&list, path);
    }
    else if (size == 2 && my_strcmp(arg[1], "-") == 0) {
        for (; my_strcmp(tmp->key, "OLDPWD") != 0; tmp = tmp->next);
        chdir(tmp->path);
        editing_pwd(&list, tmp->path);
    } else if (size == 2)
        cd_file(arg[1], list);
}