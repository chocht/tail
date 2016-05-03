/*
** my_strstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 18:09:35 2015 Pierre Chauchoy
** Last update Mon Feb 15 15:49:01 2016 Pierre Chauchoy
*/

#include <stdarg.h>
#include <stdlib.h>

char		*cp_str_in_tmp_c(char *dest, char c)
{
  char		*tmp;
  int		len;
  int		i;

  len = my_strlen(dest);
  if (!(tmp = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    tmp[i] = dest[i];
  tmp[i] = '\0';
  free(dest);
  if (!(dest = malloc(sizeof(char) * (len + 1 + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    dest[i] = tmp[i];
  free(tmp);
  dest[i++] = c;
  dest[i] = '\0';
  return (dest);
}

char		*cp_str_in_tmp_s(char *dest, char *add)
{
  char		*tmp;
  int		len;
  int		i;
  int		j;

  len = my_strlen(dest);
  if (!(tmp = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    tmp[i] = dest[i];
  tmp[i] = '\0';
  free(dest);
  if (!(dest = malloc(sizeof(char) * (len + my_strlen(add) + 1))))
    return (NULL);
  i = -1;
  while (++i < len)
    dest[i] = tmp[i];
  free(tmp);
  len = my_strlen(add);
  j = -1;
  while (++j < len)
    dest[i++] = add[j];
  dest[i] = '\0';
  return (dest);
}

char		*my_strstr(char *s, ...)
{
  int		i;
  va_list	ap;
  char		*dest;

  i = -1;
  if (!(dest = malloc(sizeof(char) * 1)))
    return (NULL);
  dest[0] = '\0';
  va_start(ap, s);
  while (++i < my_strlen(s))
    {
      if (s[i] == '%')
	{
	  if (s[++i] == 's')
	    if (!(dest = cp_str_in_tmp_s(dest, va_arg(ap, char*))))
	      return (NULL);
	}
      else
	if (!(dest = cp_str_in_tmp_c(dest, s[i])))
	  return (NULL);
    }
  va_end(ap);
  return (dest);
}
