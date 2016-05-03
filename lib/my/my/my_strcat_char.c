/*
** my_strcat_c.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Fri Apr  8 09:51:16 2016 Pierre Chauchoy
** Last update Fri Apr  8 09:51:41 2016 Pierre Chauchoy
*/

#include <stdlib.h>

char		*my_strcat_char(char *s, char c)
{
  char		*tmp;
  int		i;

  if (!(tmp = malloc(sizeof(char) * (my_strlen(s) + 1 + 1))))
    return (NULL);
  i = -1;
  while (s[++i])
    tmp[i] = s[i];
  free(s);
  tmp[i++] = c;
  tmp[i] = '\0';
  return (tmp);
}
