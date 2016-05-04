/*
** display2.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Wed May  4 08:57:43 2016 Pierre Chauchoy
** Last update Wed May  4 08:58:11 2016 Pierre Chauchoy
*/

#include "tail.h"
#include "my_printf.h"
#include "my.h"

int		disp_with_lines(t_list *list, t_parsing parsing)
{
  t_elem	*tmp;

  tmp = list->head;
  while (list->len - parsing.lines > 0)
    {
      parsing.lines++;
      tmp = tmp->next;
    }
  while (tmp)
    {
      my_printf("%s\n", tmp->file);
      tmp = tmp->next;
    }
  return (0);
}

void		disp_with_bytes2(t_elem *tmp, int len)
{
  my_printf("%s\n", &tmp->file[len]);
  tmp = tmp->next;
  while (tmp)
    {
      my_printf("%s\n", tmp->file);
      tmp = tmp->next;
    }
}

int		disp_with_bytes(t_list *list, t_parsing parsing)
{
  int		bytes;
  int		len;
  t_elem	*tmp;

  tmp = list->head;
  bytes = 0;
  while (tmp)
    {
      bytes += my_strlen(tmp->file) + 1;
      tmp = tmp->next;
    }
  tmp = list->head;
  len = 0;
  while (bytes - parsing.bytes > 0)
    {
      len++;
      parsing.bytes++;
      if (len == my_strlen(tmp->file))
	{
	  len = - 1;
	  tmp = tmp->next;
	}
    }
  disp_with_bytes2(tmp, len);
  return (0);
}
