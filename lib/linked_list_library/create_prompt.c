/*
** EPITECH PROJECT, 2020
** create prompt and terminal
** File description:
** prompt
*/

#include "../../include/mini_one.h"

char *rem_backn(char *buffer)
{
    char *test = malloc(sizeof(*test) * my_strlen(buffer) - 1);
    int back_n = 0;
    char *back = malloc(sizeof(*back));
    back[0] = '\n';

    for (int i = 0; buffer[i]; i += 1)
        if (buffer[i] == '\n')
            back_n += 1;
    if (back_n == my_strlen(buffer))
        return (back);
    for (int i = 0; buffer[i] != '\n'; i += 1) {
        test[i] = buffer[i];
    }
    return (test);
}

void minishell(t_list *env)
{
    int exit_shell = 0;
    char *buffer = NULL;
    size_t n = 10;
    t_list *tmp = env;
    int ok = 0;

    for (; my_strcmp(tmp->key, "PWD") != 0; tmp = tmp->next);
    if (isatty(0) == 1)
        my_printf("[%s] ", tmp->path);
    ok = getline(&buffer, &n, stdin);
    while (buffer && my_strcmp(buffer, "exit\n") != 0 && ok != -1) {
        buffer = rem_backn(buffer);
        launch_functions(buffer, env);
        if (isatty(0) == 1)
            my_printf("[%s]", tmp->path);
        ok = getline(&buffer, &n, stdin);
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

char *give_cwd(void)
{
    int size = 10;
    char *buffer = NULL;

    buffer = getcwd(buffer, size);
    while (!buffer) {
        size += 10;
        buffer = malloc(sizeof(*buffer) * size + 1);
        buffer = getcwd(buffer, size);
    }
}