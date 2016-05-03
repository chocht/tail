/*
** my_show_wordtab.c for lib in /home/chauch_p/librairie/lib/my/test
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu Jan 21 09:45:55 2016 Pierre Chauchoy
** Last update Mon Feb 15 16:24:49 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_show_wordtab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != '\0')
    {
      write(1, tab[i], my_strlen(tab[i]));
      write(1, "\n", 1);
    }
}
