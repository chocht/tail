/*
** main.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 10:18:45 2016 Pierre Chauchoy
** Last update Tue May  3 17:08:57 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "tail.h"
#include "my_printf.h"
#include "get_next_line.h"

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
  parsing->starting_line = -1;
  parsing->lines = DEFAULT_LINES;
  parsing->bytes = 0;
  parsing->verbose = 0;
  parsing->index = 0;
}

int		init_tail(t_tail *tail)
{
  init_list(&tail->files);
  tail->parsing.index = 0;
  init_parsing(&tail->parsing);
  tail->parsing_func[0] = NULL;
  tail->parsing_func[1] = NULL;
  return (0);
}

int		create_list_and_disp(t_tail *tail, int fd)
{
  t_list	list;
  t_elem	*tmp;
  char		*s;

  init_list(&list);
  while ((s = get_next_line(fd)))
    {
      if (add_list(&list, s))
	return (1);
      free(s);
    }
  tmp = list.head;
  while (list.len - tail->parsing.lines > 0)
    {
      tail->parsing.lines++;
      tmp = tmp->next;
    }
  while (tmp)
    {
      my_printf("%s\n", tmp->file);
      tmp = tmp->next;
    }
  return (0);
}

int		loop_disp(t_tail *tail)
{
  t_elem	*tmp;
  int		fd;

  tmp = tail->files.head;
  while (tmp)
    {
      if ((fd = open(tmp->file, O_RDONLY)) != -1)
	{
	  if (create_list_and_disp(tail, fd))
	    return (1);
	}
      else
	my_fprintf(2, "tail: cannot open '%s' for reading: No such file \
or directory\n", tmp->file);
      tmp = tmp->next;
    }
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

int		main(int argc, char **argv)
{
  if (argc == 1)
    while (1);
  if (my_tail(argv))
    return (1);
  return (0);
}
