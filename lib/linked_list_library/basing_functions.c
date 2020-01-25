/*
** EPITECH PROJECT, 2020
** basing_functions
** File description:
** basing_functions
*/

#include "../../include/mini_one.h"

void add_element(t_list **list, char *key, char *path)
{
    t_list *elem = malloc(sizeof(*elem));
    t_list *tmp = *list;

    elem->path = path;
    elem->key = key;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = elem;
}

void remove_element(t_list **list, int position)
{
    t_list *tmp1 = NULL;
    t_list *tmp2 = (*list);
    t_list *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        (*list) = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_element(t_list **list, int position, char *path, char *key)
{
    t_list *elem = malloc(sizeof(*elem));
    t_list *tmp1 = (*list);
    t_list *tmp2 = (*list);

    elem->path = path;
    elem->key = key;
    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
        if (i < position - 2 && tmp2 == NULL)
            exit(84);
    }
    tmp1->next = elem;
    elem->next = tmp2;
}

char *checker(char *buffer)
{
    int ok = 0;
    char *ret = malloc(sizeof(*buffer) * 2);

    ret[0] = '\n';
    ret[1] = '\0';
    for (int i = 0; ok == 0 && buffer[i]; i += 1)
        if (buffer[i] != ' ' && buffer[i] != '\n')
            ok = 1;
    if (ok ==  0)
        return (ret);
    else
        return (buffer);
}