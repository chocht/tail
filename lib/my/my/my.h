/*
** my.h for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 02:33:13 2016 Pierre Chauchoy
** Last update Tue Apr 12 02:22:46 2016 Pierre Chauchoy
*/

#ifndef MY_H_
# define MY_H_

# include		<stdarg.h>

void			my_putchar(char);
int			my_putstr(char*);
int			my_strlen(char*);
void			my_put_nbr(int);
void			my_putnbr_base(int, int);
int			my_getnbr(char*);
int			my_getnbr_base(char*, char*);
double			my_getnbr_f(char*);
int			my_power_rec(int, int);

char			**my_str_to_wordtab(char*, char*);
int			my_len_wordtab(char**);
void			my_show_wordtab(char**);
void			my_free_wordtab(char**);

char			*my_revstr(char*);
char			*my_strdup(char*);
char			*my_strcpy(char*, char*);
char			*my_strncpy(char*, char*, int);
char			*my_strstr(char*, ...);
char			*my_strcat_char(char*, char);

int			my_strcmp(char*, char*);
int			my_strcmp_overflow(char*, char*);
int			my_strncmp(char*, char*, int);
int			my_str_isalpha(char*);
int			my_str_isnum_pos(char*);
int			my_str_isnum(char*);

#endif /* !MY_H_ */
