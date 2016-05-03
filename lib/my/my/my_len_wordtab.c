/*
** my_len_wordtab.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 03:03:40 2016 Pierre Chauchoy
** Last update Mon Apr 11 03:03:45 2016 Pierre Chauchoy
*/

int		my_len_wordtab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != '\0');
  return (i);
}
