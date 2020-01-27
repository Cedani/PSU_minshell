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
    return (0);
}