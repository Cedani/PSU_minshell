/*
** EPITECH PROJECT, 2020
** create prompt and terminal
** File description:
** prompt
*/

#include "../../include/mini_one.h"

void minishell(t_list *env)
{
    int exit_shell = 0;
    char *buffer = NULL;
    t_list *tmp = env;

    for (; my_strcmp(tmp->key, "PWD") != 0; tmp = tmp->next);
    my_printf("[%s] ", tmp->path);
    buffer = get_next_line(0);
    while (buffer && my_strcmp(buffer, "exit") != 0) {
        launch_functions(buffer, env);
        my_printf("[%s] ", tmp->path);
        buffer = get_next_line(0);
    }
}

char **give_env(t_list *list)
{
    int size = 0;
    t_list *tmp = list;
    char **list_env = NULL;
    int i = 0;

    while (tmp) {
        size += 1;
        tmp = tmp->next;
    }
    list_env = malloc(sizeof(*list_env) * size + 1);
    tmp = list;
    while (tmp) {
        list_env[i] = malloc(sizeof(char));
        list_env[i] = my_strcat(tmp->key, "=");
        list_env[i] = my_strcat(list_env[i], tmp->path);
        i += 1;
        tmp = tmp->next;
    }
    list_env[i] = NULL;
    return (list_env);
}