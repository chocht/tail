/*
** my_strdup.c for strduplicate in /home/chauch_p/Repositories/Piscine_C_J08/ex_01
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Wed Oct  7 14:29:00 2015 Pierre Chauchoy
** Last update Tue Apr  5 08:26:55 2016 Pierre Chauchoy
*/

#include <stdlib.h>

char		*my_strdup(char *src)
{
  int		i;
  int		len;
  char		*str;

  if (!(src))
    return (NULL);
  i = -1;
  len = my_strlen(src);
  if (!(str = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  while (++i < len)
    str[i] = src[i];
  str[i] = '\0';
  return (str);
}
