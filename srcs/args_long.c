/*
** args_long.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 14:22:47 2016 Pierre Chauchoy
** Last update Tue May  3 15:22:26 2016 Pierre Chauchoy
*/

#include "tail.h"
#include "my.h"

int		p_lines_l(t_parsing *parsing, char *s)
{
  if (my_str_isnum(&s[my_strlen(LINES_LONG)]))
    return (1);
  parsing->lines = my_getnbr(&s[my_strlen(LINES_LONG)]);
  return (0);
}

int		p_bytes_l(t_parsing *parsing, char *s)
{
  if (my_str_isnum(&s[my_strlen(BYTES_LONG)]))
    return (1);
  parsing->bytes = my_getnbr(&s[my_strlen(BYTES_LONG)]);
  return (0);
}
