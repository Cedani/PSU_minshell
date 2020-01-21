/*
** EPITECH PROJECT, 2020
** list.h
** File description:
** prototype of linked listed functions
*/

#ifndef LIST
#define LIST
#include <stdlib.h>

typedef struct s_list {
    char *path;
    char *key;
    struct s_list *next;
} t_list;

typedef struct argument_s {
    char *argument;
    void(*func)(char *, t_list *);
} argument_t;

typedef struct cmd_s {
    char *cmd;
    char **arg;
    int size;
} cmd_t;

void add_element(t_list **list, char *key, char *path);
void remove_element(t_list **list, int position);
t_list *envt(char **env);
void launch_functions(char *cmd, t_list *list_env);
void cd(char *command, t_list *list);
void my_memset(char *buffer, int size);
void minishell(t_list *env);
void env(char *command, t_list *list);
void set_env(char *command, t_list *list);
char **urgent_env(void);
int cd_file(char *path, t_list *list);
char **give_env(t_list *list);
void editing_pwd(t_list **list, char *path);
void unset_env(char *command, t_list *list);
char *give_cwd(void);
void print_signal(int status);
#endif /* !LIST */