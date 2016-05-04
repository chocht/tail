/*
** args_long.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 14:22:47 2016 Pierre Chauchoy
** Last update Wed May  4 09:09:09 2016 Pierre Chauchoy
*/

#include "tail.h"
#include "my.h"

int		p_lines_l(t_parsing *parsing, char *s)
{
  if (my_str_isnum(&s[my_strlen(LINES_LONG) + 1]))
    return (1);
  parsing->lines = my_getnbr(&s[my_strlen(LINES_LONG) + 1]);
  parsing->index = 0;
  return (0);
}

int		p_bytes_l(t_parsing *parsing, char *s)
{
  if (my_str_isnum(&s[my_strlen(BYTES_LONG) + 1]))
    return (1);
  parsing->bytes = my_getnbr(&s[my_strlen(BYTES_LONG) + 1]);
  parsing->index = 1;
  return (0);
}
