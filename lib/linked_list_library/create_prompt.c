/*
** EPITECH PROJECT, 2020
** create prompt and terminal
** File description:
** prompt
*/

#include "../../include/mini_one.h"

char *rem_backn(char *buffer)
{
    int j = my_strlen(buffer);
    char *test = malloc(sizeof(char) * j);
    int back_n = 0;
    char *back = malloc(sizeof(*back) * 2);
    int i = 0;
    back[0] = '\n';
    back[1] = '\0';

    buffer = checker(buffer);
    for (int j = 0; buffer[j]; j += 1)
        if (buffer[j] == '\n')
            back_n += 1;
    if (back_n == my_strlen(buffer))
        return (back);
    for (; buffer[i] != '\n'; i += 1)
        test[i] = buffer[i];
    test[i] = '\0';
    return (test);
}

void minishell(t_list *env_t)
{
    char *buffer = NULL;
    size_t n = 0;
    t_list *tmp = env_t;
    int ok = 0;
    int i = 0;

    if (isatty(0) == 1)
        my_printf("[%s] ", give_cwd());
    ok = getline(&buffer, &n, stdin);
    buffer = rem_backn(buffer);
    while (buffer && my_strcmp(buffer, "exit") != 0 && ok != -1) {
        launch_functions(buffer, env_t);
        if (isatty(0) == 1)
            my_printf("[%s] ", give_cwd());
        ok = getline(&buffer, &n, stdin);
        buffer = rem_backn(buffer);
    }
}

char **give_env(t_list *list)
{
    int size = 0;
    t_list *tmp = list;
    char **list_env = NULL;
    int i = 0;

    if (!list)
        return NULL;
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
    return (list_env);
}

char *give_cwd(void)
{
    int size = 1;
    char *buffer = NULL;

    buffer = getcwd(buffer, size);
    while (!buffer) {
        size += 1;
        buffer = getcwd(buffer, size);
    }
    return (buffer);
}

void print_signal(int status)
{
    char *sig = strsignal(WTERMSIG(status));
    if (my_strcmp(sig, "Floating point exception") == 0)
        my_printf("Floating exception\n");
    else if (__WCOREDUMP(status))
        my_printf("Segmentation fault (core dumped)\n", sig);
    else
        my_printf("%s\n", sig);
}