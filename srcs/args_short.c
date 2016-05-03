/*
** args_short.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 14:19:58 2016 Pierre Chauchoy
** Last update Tue May  3 14:25:37 2016 Pierre Chauchoy
*/

#include "tail.h"
#include "my.h"

int		p_bytes(t_parsing *parsing, char *s)
{
  if (!s)
    return (1);
  if (my_str_isnum(s))
    return (1);
  parsing->bytes = my_getnbr(s);
  parsing->index = 1;
  return (0);
}

int		p_lines(t_parsing *parsing, char *s)
{
  if (!s)
    return (1);
  if (my_str_isnum(s))
    return (1);
  parsing->lines = my_getnbr(s);
  parsing->index = 0;
  return (0);
}
