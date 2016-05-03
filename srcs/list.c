/*
** list.c for lib in /home/chauch_p/librairie/samples/start_doubled_linked_lists
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Apr 12 03:32:05 2016 Pierre Chauchoy
** Last update Tue May  3 10:06:09 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "list.h"

void		init_list(t_list *list)
{
  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
}

void		show_list(t_list *list)
{
  t_elem	*tmp;

  tmp = list->head;
  while (tmp)
    tmp = tmp->next;
}

int		add_list(t_list *list)
{
  t_elem	*new;

  if (!(list) || !(new = malloc(sizeof(t_elem))))
    return (1);
  new->next = NULL;
  if (list->tail == NULL)
    {
      new->prev = NULL;
      list->head = new;
    }
  if (list->tail != NULL)
    {
      new->prev = list->tail;
      list->tail->next = new;
    }
  list->tail = new;
  list->len++;
  return (0);
}

int		free_list(t_list *list)
{
  t_elem	*old;
  t_elem	*tmp;

  if (!(list))
    return (1);
  tmp = list->head;
  while (tmp)
    {
      old = tmp;
      tmp = tmp->next;
      free(old);
    }
  free(list);
  return (0);
}
