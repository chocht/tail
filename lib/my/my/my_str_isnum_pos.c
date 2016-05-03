/*
** my_str_isnum_pos.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 03:03:00 2016 Pierre Chauchoy
** Last update Mon Apr 11 03:03:09 2016 Pierre Chauchoy
*/

int		my_str_isnum_pos(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] > 57 || str[i] < 48)
	return (1);
      i = i + 1;
    }
  return (0);
}
