/*
** args_simple.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 14:19:19 2016 Pierre Chauchoy
** Last update Tue May  3 14:23:54 2016 Pierre Chauchoy
*/

#include "tail.h"

void		p_help(t_parsing *parsing)
{
  parsing->help = 1;
}

void		p_verb(t_parsing *parsing)
{
  parsing->verbose = 1;
}
