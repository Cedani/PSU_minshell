/*
** EPITECH PROJECT, 2020
** MY
** File description:
** libmy functions
*/

#ifndef MY
#define MY
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

char **my_str_to_word_array(char *str, int *nb_lines);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat (char *dest , char const *src);
int alpha(char c);
#endif /* !MY */
