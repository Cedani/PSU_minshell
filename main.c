/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "include/mini_one.h"

int main(int argc, char **argv, char **env)
{
    t_list *list_env = envt(env);
    minishell(list_env);
    // remove_element(&list_env, 1);
    // while (list_env) {
    //     my_printf("%s=%s\n", list_env->key, list_env->path);
    //     list_env = list_env->next;
    // }
    return (0);
}