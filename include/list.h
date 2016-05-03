/*
** list.h for list in /home/chauch_p/librairie/samples/start_doubled_linked_lists
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Mar 15 09:42:50 2016 Pierre Chauchoy
** Last update Tue May  3 10:06:28 2016 Pierre Chauchoy
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_elem
{
  struct s_elem		*prev;
  struct s_elem		*next;
}			t_elem;

typedef struct		s_list
{
  int			len;
  struct s_elem		*head;
  struct s_elem		*tail;
}			t_list;

void			swap_elem(t_list*, t_elem*, t_elem*);
void			init_list(t_list*);
void			show_list(t_list*);
int			add_list(t_list*);
int			free_list(t_list*);

#endif /* !LIST_H_ */
