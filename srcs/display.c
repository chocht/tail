/*
** display.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Wed May  4 08:41:13 2016 Pierre Chauchoy
** Last update Wed May  4 08:58:37 2016 Pierre Chauchoy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "tail.h"
#include "my_printf.h"
#include "get_next_line.h"

static int	create_list_and_disp(t_tail *tail, int fd)
{
  t_list	list;
  char		*s;

  init_list(&list);
  while ((s = get_next_line(fd)))
    {
      if (add_list(&list, s))
	return (1);
      free(s);
    }
  if (tail->parsing_func[tail->parsing.index])
    tail->parsing_func[tail->parsing.index](&list, tail->parsing);
  return (0);
}

static int		scan_files_list(t_list *files)
{
  files = files;
  return (0);
}

int		loop_disp(t_tail *tail)
{
  t_elem	*tmp;
  int		fd;

  tmp = tail->files.head;
  if (scan_files_list(&tail->files))
    tail->parsing.verbose = 1;
  while (tmp)
    {
      if ((fd = open(tmp->file, O_RDONLY)) != -1)
	{
	  if (tail->parsing.verbose == 1)
	    my_printf("==> %s <==\n", tmp->file);
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
