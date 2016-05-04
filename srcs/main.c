/*
** main.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 10:18:45 2016 Pierre Chauchoy
** Last update Wed May  4 08:42:12 2016 Pierre Chauchoy
*/

#include "tail.h"

int		main(int argc, char **argv)
{
  if (argc == 1)
    while (1);
  if (my_tail(argv))
    return (1);
  return (0);
}
