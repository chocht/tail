/*
** my_tail.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Wed May  4 08:37:29 2016 Pierre Chauchoy
** Last update Wed May  4 08:42:58 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "tail.h"

static void	init_parsing(t_parsing *parsing)
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
  parsing->starting_line = -1;
  parsing->lines = DEFAULT_LINES;
  parsing->bytes = 0;
  parsing->verbose = 0;
  parsing->index = 0;
}

static int	init_tail(t_tail *tail)
{
  init_list(&tail->files);
  tail->parsing.index = 0;
  init_parsing(&tail->parsing);
  tail->parsing_func[0] = &disp_with_lines;
  tail->parsing_func[1] = &disp_with_bytes;
  return (0);
}

int		my_tail(char **argv)
{
  t_tail	tail;

  init_tail(&tail);
  if (parsing(argv, &tail))
    {
      free_list(&tail.files);
      return (1);
    }
/*   my_printf("lines = %d\nbytes = %d\nindex active = %d\n\ */
/* verbose = %d\n", tail.parsing.lines,tail.parsing.bytes, */
/* 	    tail.parsing.index, tail.parsing.verbose); */
  if (loop_disp(&tail))
    {
      free_list(&tail.files);
      return (1);
    }
  free_list(&tail.files);
  return (0);
}
