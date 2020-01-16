/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** useful functions
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

typedef struct func_list_s {
    char c;
    void (*fun)(va_list);
} func_list_t;
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *);
int my_put_nbr(int nb);
char *calc_base(int nb, char const *base);
char *my_revstr(char *str);
void prt_string(va_list ap);
void prt_char(va_list ap);
void prt_int(va_list ap);
void prt_uns_int(va_list ap);
void prt_octal(va_list ap);
void prt_flag_s(va_list ap);
void prt_flag_point(va_list ap);
void prt_uns_bin(va_list ap);
void prt_hexadecimal_maj(va_list ap);
void prt_hexadecimal_min(va_list ap);
void my_printf(char *s, ...);
char *put_nbr_base(long long nb, char const *base);
void my_prt_nb_char(va_list ap);
void prt_mod(va_list ap);
int my_getnbr(char const *str);
int for_spe(va_list ap, char s);
int count_digit(int nb);
int print_zero(int nb_zer, char s, va_list ap);
int my_strtol(char *str, char **ptr);
char *attrib_string_strtol(char *str, char **ptr, int i);
int count_space_strtol(char *str);
int find_num(int i, char *str);
int error(char *str, int i);
int attrib_num(char const *str, int i);
int attrib_sign(char const *str, int i);
void my_printf(char *s, ...);
void error_list(int ac, char **av);
#endif /* !MY_H_ */
