/*
** my_strcmp_overflow.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 03:01:39 2016 Pierre Chauchoy
** Last update Mon Apr 11 03:01:44 2016 Pierre Chauchoy
*/

int		my_strcmp_overflow(char *s1, char *big)
{
  int		i;

  i = -1;
  if (my_strlen(big) < my_strlen(s1))
    return (1);
  if (my_strlen(big) > my_strlen(s1))
    return (0);
  while (big[++i] != '\0')
    if (s1[i] > big[i])
      return (1);
  return (0);
}
