/*
** EPITECH PROJECT, 2020
** create_env.c
** File description:
** create environment
*/

#include "../../include/mini_one.h"

char *cat_path(char *var)
{
    int i = 0;
    int k = 0;
    char *str = NULL;

    for (; var[i] != 61; i += 1);
    str = malloc(sizeof(*str) * i + 1);
    for (; k < i; k += 1)
        str[k] = var[k];
    str[k] = '\0';
    return (str);
}

int det_path_value(char **env)
{
    for (int i = 0; env[i]; i += 1)
        if (my_strcmp("PATH", cat_path(env[i])) == 0)
            return (i);
}

char *give_value_path(char *path)
{
    int i = 0;
    int k = 0;
    int size = my_strlen(path);
    char *value_path = NULL;

    for (; path[i] != 61; i += 1);
    i += 1;
    size -= i;
    value_path = malloc(sizeof(*value_path) * size + 1);
    for (; path[i]; i += 1) {
        value_path[k] = path[i];
        k += 1;
    }
    value_path[k] = '\0';
    return (value_path);
}

void set_old(t_list *list)
{
    t_list *tmp = list;
    char *cwd;

    for (;tmp && my_strcmp(tmp->key, "OLDPWD") != 0; tmp = tmp->next);
    if (tmp)
        give_old(tmp->path, 1);
    else {
        cwd = give_cwd();
        give_old(cwd, 1);
    }
    tmp = list;
    for (;tmp && my_strcmp(tmp->key, "HOME") != 0; tmp = tmp->next);
    if (tmp)
        give_home(tmp->path, 1);
}

t_list *envt(char **env)
{
    t_list *list_env = NULL;
    char *key = NULL;
    char *value = NULL;

    if (!env[0]) {
        set_old(list_env);
        return list_env;
    }
    for (int i = 0; env[i]; i += 1) {
        key = cat_path(env[i]);
        value = give_value_path(env[i]);
        add_element(&list_env, key, value);
    }
    set_old(list_env);
    return (list_env);
}