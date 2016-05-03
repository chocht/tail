/*
** parsing.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 12:06:02 2016 Pierre Chauchoy
** Last update Tue May  3 14:52:01 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "tail.h"
#include "my.h"

void		init_parsing(t_parsing *parsing)
{
  parsing->simple_args[0] = HELP;
  parsing->simple_args[1] = VERB_1;
  parsing->simple_args[2] = VERB_2;
  parsing->simple_args[3] = NULL;
  parsing->short_args[0] = BYTES_SHORT;
  parsing->short_args[1] = LINES_SHORT;
  parsing->short_args[2] = NULL;
  parsing->long_args[0] = BYTES_LONG;
  parsing->long_args[1] = LINES_LONG;
  parsing->long_args[2] = NULL;
  parsing->args_simple[0] = &p_help;
  parsing->args_simple[1] = &p_verb;
  parsing->args_simple[2] = &p_verb;
  parsing->args_simple[3] = NULL;
  parsing->args_short[0] = &p_bytes;
  parsing->args_short[1] = &p_lines;
  parsing->args_short[2] = NULL;
  parsing->args_long[0] = &p_bytes_l;
  parsing->args_long[1] = &p_lines_l;
  parsing->args_long[2] = NULL;
  parsing->lines = DEFAULT_LINES;
  parsing->starting_line = -1;
  parsing->bytes = 0;
  parsing->verbose = 0;
  parsing->help = 0;
}

int		parsing(char **argv, t_tail *tail)
{
  int		i;
  int		j;

  i = 0;
  while (argv[++i])
    {
      j = -1;
      while (tail->parsing.simple_args[++j] &&
	     my_strcmp(tail->parsing.simple_args[j], argv[i]));
      if (tail->parsing.args_simple[j])
        tail->parsing.args_simple[j](&tail->parsing);
      else
	if (add_list(&tail->files, argv[i]))
	  return (1);
    }
  show_list(&tail->files);
  free_list(&tail->files);
  return (0);
}
