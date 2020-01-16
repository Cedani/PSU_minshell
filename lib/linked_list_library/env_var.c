/*
** EPITECH PROJECT, 2020
** env_var
** File description:
** env, setenv and unsetenv
*/

#include "../../include/mini_one.h"

void env(char *command, t_list *list)
{
    while (list) {
        my_printf("%s = %s\n", list->key, list->path);
        list = list->next;
    }
}

void set_env(char *command, t_list *list)
{
    int size = 0;
    char **arg = my_str_to_word_array(command, &size);
    int ok = 0;
    t_list *tmp = list;

    if (size != 3) {
        my_printf("bad number of argument\n");
        return;
    }
    while (tmp) {
        if (my_strcmp(tmp->key, arg[1]) == 0) {
            tmp->path = arg[2];
            ok = 1;
        }
        tmp = tmp->next;
    }
    if (ok == 0)
        add_element(&list, arg[1], arg[2]);
}

void unset_env(char *command, t_list *list)
{
    int size = 0;
    char **arg = my_str_to_word_array(command, &size);
    t_list *tmp = list;
    int i = 0;

    while (tmp && my_strcmp(tmp->key, arg[1]) != 0) {
        i += 1;
        tmp = tmp->next;
    }
    i += 1;
    if (my_strcmp(tmp->key, arg[1]) == 0)
        remove_element(&list, i);
}