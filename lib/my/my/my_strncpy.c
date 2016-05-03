/*
** my_strncpy.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 18:09:04 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:31:23 2016 Pierre Chauchoy
*/

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = -1;
  while (++i < n && src[i] != '\0')
    dest[i] = src[i];
  return (dest);
}
