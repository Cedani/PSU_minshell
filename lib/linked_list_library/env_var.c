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
        my_printf("%s=%s\n", list->key, list->path);
        list = list->next;
    }
}

void sub(t_list *list, char **arg, t_list *tmp, int size)
{
    char *test = malloc(sizeof(*test));

    if (tmp)
        tmp->path = arg[2];
    else if (size == 2)
        add_element(&list, arg[1], test);
    else
        add_element(&list, arg[1], arg[2]);
}

int my_strisalpha(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (alpha(str[i]) == 1)
            return (1);
    return (0);
}

void set_env(char *command, t_list *list)
{
    int size = 0;
    char **arg = my_str_to_word_array(command, &size);
    t_list *tmp = list;

    if (size == 1) {
        env(command, list);
        return;
    }
    if (size > 3) {
        my_printf("too many argument\n");
        return;
    }
    if (my_strisalpha(arg[1]) == 1)
    {
        my_printf("setenv: Variable name must");
        my_printf(" contain alphanumeric characters.\n");
        return;
    }
    for (; tmp && my_strcmp(tmp->key, arg[1]) != 0; tmp = tmp->next);
    sub(list, arg, tmp, size);
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
    if (tmp && my_strcmp(tmp->key, arg[1]) == 0)
        remove_element(&list, i);
}
