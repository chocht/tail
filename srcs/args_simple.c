/*
** args_simple.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 14:19:19 2016 Pierre Chauchoy
** Last update Tue May  3 15:56:23 2016 Pierre Chauchoy
*/

#include "tail.h"

int		p_help(t_parsing *parsing)
{
  parsing = parsing;
  return (2);
}

int		p_verb(t_parsing *parsing)
{
  parsing->verbose = 1;
  return (0);
}
