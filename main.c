/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "include/mini_one.h"

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL) {
        env = urgent_env();
    }
    t_list *list_env = envt(env);
    //char **test = give_env(list_env);
    minishell(list_env);
    return (0);
}