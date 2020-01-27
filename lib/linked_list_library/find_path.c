/*
** EPITECH PROJECT, 2020
** find path
** File description:
** finding path variable value
*/

#include "../../include/mini_one.h"

static const argument_t func[] = {
    {"cd", cd},
    {"env", env},
    {"setenv", set_env},
    {"unsetenv", unset_env},
    NULL,
};

char *find_path(t_list *list)
{
    for (;list && my_strcmp(list->key, "PATH") != 0; list = list->next);
    if (list)
        return (list->path);
    else
        return NULL;
}

int check_built(char **arg, t_list *list, char *cmd)
{
    for (int i = 0; i < 4; i += 1) {
        if (my_strcmp(arg[0], func[i].argument) == 0) {
            func[i].func(cmd, list);
            return (1);
        }
    }
    return (0);
}

void execute_functions(cmd_t *cmd_arg, t_list *list)
{
    int status = 0;
    int i = fork();

    if (i == 0) {
        execve(cmd_arg->arg[0], cmd_arg->arg, give_env(list));
        if (EACCES == errno) {
            my_printf("%s: Permission denied.\n", cmd_arg->arg[0]);
        }
        else if (ENOEXEC == errno) {
            my_printf("%s: Exec format error. Wrong ", cmd_arg->arg[0]);
            my_printf("Architecture.\n");
        }
        exit (0);
    } else
        waitpid(i, &status, 0);
    if (WIFSIGNALED(status))
        print_signal(status);
}

void check_existence(char **env, cmd_t *cmd_arg, int size2, t_list *list_env)
{
    int ok = -1;
    char *test = NULL;

    for (int i = 0; env[i] && ok != 0; i += 1) {
        test = my_strcat(env[i], "/");
        test = my_strcat(test, cmd_arg->arg[0]);
        ok = access(test, X_OK);
        if (ok == 0) {
            cmd_arg->arg[0] = test;
            execute_functions(cmd_arg, list_env);
            return;
        }
    }
    if (ok == -1 && my_strcmp(cmd_arg->arg[0], "\n") != 0)
        my_printf("%s: Command not found.\n", cmd_arg->arg[0]);
}

void launch_functions(char *cmd, t_list *list_env)
{
    int size = 0;
    int size2 = 0;
    char *path = find_path(list_env);
    char **env = my_str_to_word_array(path, &size2);
    cmd_t *cmd_arg = malloc(sizeof(*cmd_arg));

    cmd_arg->arg = my_str_to_word_array(cmd, &size);
    if (check_built(cmd_arg->arg, list_env, cmd) == 1)
        return;
    if (!path) {
        my_printf("%s: Command not found.\n", cmd_arg->arg[0]);
        return;
    }
    cmd_arg->size = size;
    cmd_arg->cmd = cmd;
    if (access(cmd_arg->arg[0], X_OK) == 0)
        execute_functions(cmd_arg, list_env);
    else
        check_existence(env, cmd_arg, size2, list_env);
}