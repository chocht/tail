/*
** main.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 10:18:45 2016 Pierre Chauchoy
** Last update Tue May  3 14:52:21 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "tail.h"

int		init_tail(t_tail *tail)
{
  init_list(&tail->files);
  tail->parsing.index = 0;
  init_parsing(&tail->parsing);
  tail->parsing_func[0] = NULL;
  tail->parsing_func[1] = NULL;
  return (0);
}

int		my_tail(__attribute__((unused))char **argv)
{
  t_tail	tail;

  init_tail(&tail);
  if (parsing(argv, &tail))
    return (1);
  return (0);
}

int		main(int argc, char **argv)
{
  if (argc == 1)
    while (1);
  if (my_tail(argv))
    return (1);
  return (0);
}
