/*
** my_printf_func_3.c for lib in /home/chauch_p/librairie/lib/my/my_printf
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Feb 16 16:53:45 2016 Pierre Chauchoy
** Last update Tue Feb 16 16:53:46 2016 Pierre Chauchoy
*/

#include "my_printf.h"

void		printf_bin(t_printf *printf)
{
  my_put_unsigned_nbr_printf(va_arg(printf->ap, int), 2, printf);
}

void		printf_tab(t_printf *printf)
{
  my_show_tab(va_arg(printf->ap, char**), printf);
}
