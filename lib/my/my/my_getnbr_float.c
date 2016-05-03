/*
** my_getnbr_float.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 21:37:53 2016 Pierre Chauchoy
** Last update Mon Apr 11 21:37:54 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_getnbr_f_dec(char *s, int i, double *nb)
{
  double	j;

  j = 10;
  while (s[i] != '\0')
    {
      *nb = *nb + (s[i] - 48) / j;
      i++;
      j *= 10;
    }
}

double		my_getnbr_f(char *s)
{
  double	nb;
  int		i;

  nb = 0;
  i = 0;
  if (s[0] == '-')
    i++;
  while (s[i] != '\0' && s[i] != '.')
    {
      nb = nb * 10 + (s[i] - 48);
      i++;
    }
  if (s[i] == '.')
    my_getnbr_f_dec(s, ++i, &nb);
  if (s[0] == '-')
    return (-nb);
  return (nb);
}
