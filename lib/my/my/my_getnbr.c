/*
** my_getnbr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 17:19:23 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:21:48 2016 Pierre Chauchoy
*/

int		my_getnbr(char *str)
{
  int		i;
  int		j;
  int		nb;

  i = my_strlen(str) - 1;
  j = 1;
  nb = 0;
  while (i >= 0)
    {
      nb = nb + ((str[i] - 48) * j);
      j = j * 10;
      i = i - 1;
      while (str[i] == '-')
	{
	  nb = -nb;
	  i = i - 1;
	  if (i == 0)
	    return (-nb);
	}
    }
  return (nb);
}
